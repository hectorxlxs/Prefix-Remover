#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;

int main(){

fstream file;
string dir;
string cad;
string aux;

string prefix;

int counter = 0;

cout<<"Write files direction: ";
getline(cin,dir);
cout<<"Write the prefix to remove: ";
cin>>prefix;

aux = "dir " + dir + "/B > names.txt"; //Windows command to copy all file or folders names on names.txt
system(aux.c_str()); //Executing the command

file.open("names.txt", ios::in);
if(file){

    while(!file.eof()){

        getline(file,cad);
        if(cad.substr(0,prefix.length()) == prefix){

            aux = "rename " + dir + "\\" + cad + " " + cad.substr(prefix.length());
            system(aux.c_str());

            counter++;
        }
    }
    file.close();
    cout<<counter<<" files have been modified";
}
else{cout<<"There was an error, the file names.txt was not found";}

getch();

return 0;}
