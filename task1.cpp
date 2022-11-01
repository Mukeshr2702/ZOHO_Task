#include <iostream>
#include <dirent.h>
#include <vector>
#include<fstream>
#include<thread>
#include<chrono>
using namespace std;
using namespace std::chrono;
void fileread(string text)
{
     string temp;
     ifstream file(text);
     while(getline(file,temp));
     cout<<endl;
     file.close();
    	char  twoD[10][30];
	 int i=0, j = 0, k = 0, l = 0;
 
 
	 for (i = 0; temp[i] != '\0'; i++)
	 {
		if (temp[i] == ' ')
		{
			twoD[k][j] = '\0';
			k ++;
			j = 0;
		}
		else
		{
			twoD[k][j] = temp[i];
			j ++;
		}
	}
 
	twoD[k][j] = '\0';
 
	j = 0;
	for (i = 0; i < k; i++)
	{
		for (l = 1; l < k + 1; l++)
		{
			if ( l == i)
			{
				continue;
			}
 
			if (strcmp (twoD[i], twoD[l]) == 0) {
				twoD[l][j] = '\0';
			}
		}
	}
	j = 0;
   string t;
	for (i = 0; i < k + 1; i++)
	{
         t+=twoD[i];
         t=t+" ";  
	}
  ofstream MyFile(text);
  MyFile<<t;
  MyFile.close();
  }

int main()
{
   auto start = high_resolution_clock::now();
   DIR *dr;
   int count=0;
   vector<string> text;
   struct dirent *en;
   dr = opendir("E:/task");
   if (dr) {
      while ((en = readdir(dr)) != NULL) {
         string t=en->d_name;
         if(t.find(".txt")!= string::npos){
            count++;
          text.push_back(t);
         }
          }
      closedir(dr); 
   }
   cout<<count;
   thread mythreads[10];
   if(count<10)
   {
      for(int i=0;i<count;i++)
      {
         mythreads[i]=thread(fileread,text[i]);
      }
      for(int i=0;i<count;i++)
      {
         mythreads[i].join();
      }
   }
   else if(count>10)
   {
      int j=0;
      while(j<count)
      {
           for(int i=0;i<10;i++)
         {
            mythreads[i]=thread(fileread,text[j++]);
            if(j==count)
            {
               break;
            }
         }
         for(int i=0;i<10;i++)
         {
            mythreads[i].join();
             if(j==count)
            {
               break;
            }
         }
      }
      }   
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Microsec : " <<duration.count() << endl;
}