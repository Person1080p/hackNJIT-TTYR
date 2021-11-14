#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iterator>
#include "pstream.h"
using namespace std;
void printr(string inp)
{
    string prints = "echo " + inp + " > /dev/usb/lp0";
    char command[1024];
    strcpy(command, prints.c_str());
    system(command);
}
string result(string cmd)
{
    // run a process and create a streambuf that reads its stdout and stderr
    redi::ipstream proc(cmd, redi::pstreams::pstdout | redi::pstreams::pstderr);
    std::string line;
    // read child's stdout
    string out = "";
    while (std::getline(proc.out(), line))
    {
        //std::cout << "stdout: " << line << '\n';
        out = line + " " + out;
    }
    //cout << out << "\n";
    return out;
    if (proc.eof() && proc.fail())
        proc.clear();
    // read child's stderr
    while (std::getline(proc.err(), line))
        std::cout << "stderr: " << line << '\n';
}
void start(){
    string starts = "";
    starts = result("whoami") + starts;
    starts = "@" +starts;
    starts = result("curl ifconfig.me") + starts;
    starts = ":" +starts;
    starts = result("pwd") + starts;
    starts = "$" +starts;
    printr(starts);
}
int main()
{
    start();
    string inp;
    while (true)
    {
        printr("$");
        
        //cin >> inp;
        getline(cin,inp);
        printr(inp);
        string output = result(inp.c_str());

        //replace(output.begin(), output.end(), "\n", " ");
        printr(result(inp));
        //cout << result(output);
    }
    return 0;
}