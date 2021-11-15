#include<iostream>
#include <string.h>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;
                                   
void printr(string inp){ //gets input string command and sends string directly to paralel0
    string prints = "echo " + inp + " > /dev/usb/lp0";//
    //prints = inp;//
    char command[1024];
    strcpy(command, prints.c_str());
    system(command);
}
void result(string inp){//gets input string command and sends execution to paralel0
    string prints = inp + " > output.txt | bash";
    char command[1024];
    strcpy(command, prints.c_str());
    system(command);
    //
    string outLoc = "\"$(cat output.txt)\"";
    printr(outLoc);
    //strcpy(command, prints.c_str());
    //system(command);

}
int main() {
    string inp;
    while (1){
        getline(cin,inp);
        printr(inp);//
        //cout << inp;
        result(inp);//
    }
}