#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>
//convert text to csv

int main(int argc, char *argv[]){

std::cout<<"\nConverting...";

time_t current_time;
time(&current_time);
tm *tm_local = localtime(&current_time);
std::string date = asctime(tm_local);

date.erase(remove(date.begin(), date.end(), ':'), date.end());
date.erase(remove(date.begin(), date.end(), ' '), date.end());
date.erase(date.end()-11, date.end()-5);

std::string name = "ConvMail";
name.append(date);
name.erase(remove(name.begin(), name.end(), '\n'), name.end());
name.append(".csv");

std::ifstream mailfile;
std::ofstream exportfile;
mailfile.open(argv[1]);
exportfile.open( name.c_str(), std::ios::out | std::ios::app);
std::string line;

  if (mailfile.is_open())
  {
      bool columntitle = true;
    while ( getline (mailfile,line) )
    {
      if(columntitle){
        exportfile << "Email List,\n";
        columntitle = false;
      }
      exportfile << line << ", \n";
    }
    std::cout << "Convert Successful (" << name << ")\n";
    mailfile.close();
  }
  else
    std::cout << "Unable to open file";

return 0;
}
