//add
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <time.h>
using namespace std;

string getTime()
{
    time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y%m%d-%H%M%S",localtime(&timep) );
    return tmp;
}
int main(){
string   time = getTime();
//cout << time;
DIR    *dir;
struct    dirent    *ptr;
dir = opendir("."); ///open the dir

// char * DistAll = "Files.txt";
ofstream outfile(("AfileLog="+time+".txt").c_str(), ios::app);
string temp;
while((ptr = readdir(dir)) != NULL) ///read the list of this dir
{
    #ifdef _WIN32
        //printf("d_name: %s\n", ptr->d_name);
        outfile << ptr->d_name<<endl;
      //  ofstream ofn(DistAll);  //输出文件流
    #endif
}
outfile.close();
closedir(dir);
}
