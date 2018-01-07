#include<iostream>
#include<fstream>
#include<ctype.h>
#include<string>
#include<vector>

using namespace std;

ifstream infile;

vector<string> reverseLine(string line);
int firstNonRecurringChar(string str);

int main()
{
   string filepath ="/Users/MarcusJordan/Dropbox/ProgrammingExercises/TestFiles/fnr.txt";
   infile.open(filepath);

   if(!infile) cout << "error" << endl;

   string line;
   int index;

   while(getline(infile,line))
   {
      index = firstNonRecurringChar(line);
      cout << line << " " << index  << " " << line[index] << "\n";
   }
   return 0;
}

vector<string> reverseLine(string ln)
{
  vector<string> line;
  string word = "";

  for(int i = 0; i < ln.length(); i++)
  {
    word += ln[i];
    if(isspace(ln[i]))
    {
      line.push_back(word);
      word = "";
    }
  }
  line.push_back(word + " ");

  int words = line.size();
  if(words < 1) return line;

  for(int start = 0, end = words - 1;  start < end; start++, end--)
  {
    string temp = line[start];
    line[start] = line[end];
    line[end] = temp;
  }
  return line;
}

int firstNonRecurringChar(string str)
{
    int letters[26] = {0};

    for(int i = 0; i < str.length(); i++)
      letters[(toupper(str[i]) - 65)]++ ;

    for(int i = 0; i < str.length(); i++)
      if(letters[(toupper(str[i]) - 65)] == 1)
          return i;
    return -1;
}
