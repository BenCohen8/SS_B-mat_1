#include "mat.hpp"
#include <iostream>


using namespace std;
using namespace ariel;


string ariel::mat(int cols,int rows,char x1,char x2)
{
	string x;
	if(cols%2==0||rows%2==0||x1==' '||x2==' '||x1=='\n'||x2=='\n'||x1=='\t'||x2=='\t'||cols<=0||rows<=0)
	{
		string ex="not a valid code";
		throw invalid_argument(ex);
	
	}
		int min=0;
		int rug[rows][cols];
		for (int i = 0; i < rows; i++)
		{
		    for (int  j = 0; j < cols;j++)
		    {
				rug[i][j]=0;
				}
				
		    
			x.push_back('\n');
		}  
		if(cols<rows)
		{
		    min =cols;
		}else
		{
		    min=rows;
		}
		for (int i = 0; i <= min/2; i++)
		{
		    if (i%2==0)
		    {
		        for (int j = i; j < cols-i; j++)
		        {
		            rug[i][j]=1;
		            rug[rows-i-1][j]=1;
		        }
		        for (int j = i; j < rows-i; j++)
		        {
		            rug[j][i]=1;
		            rug[j][cols-1-i]=1;
		        }     
		    }else
		    {
		        for(int j = i; j < cols-i; j++)
		        {
		            rug[i][j]=0;
		            rug[rows-i-1][j]=0;
		        }
		        for (int j = i; j < rows-i; j++)
		        {
		            rug[j][i]=0;
		            rug[j][cols-1-i]=0;
		        }  
		    }
		}
		for (int i = 0; i < rows; i++)
		{
		    for (int  j = 0; j < cols;j++)
		    {
				if (rug[i][j]==1)
				{
					x.push_back(x1);
				}
				if (rug[i][j]==0)
				{
					x.push_back(x2);
				}
				
		    }
			x.push_back('\n');
		}  
	
	return x;
}
