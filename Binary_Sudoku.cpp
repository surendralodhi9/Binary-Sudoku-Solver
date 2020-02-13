#include<bits/stdc++.h>
using namespace std;
void printSudoku(int n,string s[])
{
	
	for(int i=0;i<n;i++)
	{	
		for(int j=0;j<n;j++)
		   cout<<s[i][j]<<" ";
		cout<<endl;
	}	
}
bool checkUp(int r,int c,int cur,int n,string s[])
{
	
	if(r-2>=0&&s[r-2][c]==s[r-1][c]&&s[r-1][c]==cur)
		return false;
	    
	return true;	
}
bool checkLeft(int r,int c,int cur,int n,string s[])
{
	
	if(c-2>=0&&s[r][c-2]==s[r][c-1]&&s[r][c-1]==cur)
		return false;
	
	return true;	
}

bool checkDown(int r,int c,int cur,int n,string s[])
{
	
	if(r+2<n&&s[r+2][c]==s[r+1][c]&&s[r+1][c]==cur)
		return false;
		
	return true;	
}
bool checkRight(int r,int c,int cur,int n,string s[])
{
	
	if(c+2<n&&s[r][c+2]==s[r][c+1]&&s[r][c+1]==cur)
		return false;
	return true;	
}
bool checkMidRow(int r,int c,int cur,int n,string s[])
{
	if(r-1>=0&&r+1<n&&s[r-1][c]==s[r+1][c]&&s[r+1][c]==cur)
	    return false;
	return true;
	
}
bool checkMidCol(int r,int c,int cur,int n,string s[])
{
	if(c-1>=0&&c+1<n&&s[r][c-1]==s[r][c+1]&&s[r][c+1]==cur)
	    return false;
	return true;
	
}
bool checkEqualInRow(int r,int c,int cur,int n,string s[])
{
	int zero=0,one=0;
	for(int i=0;i<n;i++)
	{
		if(s[r][i]=='0')
		   zero++;
		else if(s[r][i]=='1')
		    one++;
	}
	if(cur=='0')
	   zero++;
	else
	   one++;
	   
	if(zero>n/2||one>n/2)
	     return false;
	     
	return true;
}
bool checkEqualInCol(int r,int c,int cur,int n,string s[])
{
	int zero=0,one=0;
	for(int i=0;i<n;i++)
	{
		if(s[i][c]=='0')
		   zero++;
		else if(s[i][c]=='1')
		    one++;
	}
	if(cur=='0')
	   zero++;
	else
	   one++;
	   
	if(zero>n/2||one>n/2)
	     return false;
	     
	return true;

}

bool isOk(int i,int r,int c,int n,string s[])
{
	
	char cur=char(i+'0');
	
	if(!checkLeft(r,c,cur,n,s))
	     return false;
	
	if(!checkRight(r,c,cur,n,s))
	    return false;
	
	if(!checkUp(r,c,cur,n,s))
	    return false;
	    
	if(!checkDown(r,c,cur,n,s))
	    return false;
	
	if(!checkMidRow(r,c,cur,n,s))
	    return false;
	
	if(!checkMidCol(r,c,cur,n,s))
	    return false;
	
    if((!checkEqualInRow(r,c,cur,n,s))||(!checkEqualInCol(r,c,cur,n,s)))
	    return false;	
	
	return true;
	
}
bool checkUniqueRow(int n, string s[])
{
	
	set<string> st;
	for(int i=0;i<n;i++)
	  st.insert(s[i]);
	if(st.size()!=n)
	   return false;	   
	return true;
	
}
bool checkUniqueCol(int n,string s[])
{
	set<string> st;
	for(int i=0;i<n;i++)
	{
		string temp;
		for(int j=0;j<n;j++)
		   temp+=s[j][i];
		st.insert(temp);
		
	}
	if(st.size()!=n)
	  return false;
	  
	return true;
	
}
void solveSudoku(int r,int c,int n,string s[], int &Flag)
{
	if(Flag)
	  return;
	if(r==n)
	{
		if(checkUniqueRow(n,s)&&checkUniqueCol(n,s))
		{
		    printSudoku(n,s);
		    Flag=1;
		}		      
		return;
	}
	if(s[r][c]!=' ')
	solveSudoku(c==(n-1)?r+1:r,(c+1)%n,n,s,Flag);
	else
	{
		for(int i=0;i<=1;i++)
		{
			if(isOk(i,r,c,n,s))
			{
				s[r][c]=char(i+'0');
				
				solveSudoku(c==(n-1)?r+1:r,(c+1)%n,n,s,Flag);
				
			}
		}
		s[r][c]=' ';
				
	}

}
string *convertFileIntoMatrix()
{
	

	FILE *fp;
	char filename[]="input14.txt";//Change filename according to inputfile
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		cout<<"Unable to read the file"<<endl;
		return NULL;
	}
	else
	{
		int ch;
		int n=0;
		while((ch=getc(fp))!=EOF)
		{
			if(ch=='\n')
			 break;
			n++;
		}
		string *s=new string[n];
		fclose(fp);
		fp=fopen(filename,"r");
		string temp;
		int i=0;
		while((ch=getc(fp))!=EOF)
		{
			if(ch!='\n')
			 temp+=ch;
			 else
			 {
			 	if(i<n)
			 	s[i++]=temp;
			 	temp="";
			 }
			
		}
		if(i<n)
		s[i++]=temp;
		
		fclose(fp);
		return s;
	
	}

	return NULL;
	
}
int main()
{
	
	string *s1=convertFileIntoMatrix();
	if(s1==NULL)
	  return 0;
	int n1=s1[0].size();
	
	/*int n=6;
	string s[n]={"1  0  ",
	             "  00 1",
				 " 00  1",
				 "      ",
				 "00 1  ",
				 " 1  00"};
				 */
		
	/*int n=10;
    string s[n]={"0   0 1 0 ",
                 "        00",
                 " 00   1   ",
                 "     1  11",
                 "0  1  11 0",
                 "1 01  1   ",
                 " 0  1  0 0",
                 "   0 0 0 1",
                 " 00       ",
                 "  00   0  "};
                 */
                
    /*int n=12;
    string s[n]={"    0 1 0   ",
                 "  1   00  10",
                 "  1         ",
                 "     1 00 0 ",
                 "           1",
                 "      1 0 11",
                 "011         ",
                 "       0 00 ",
                 "   11  0    ",
                 "          00",
                 "1  0 1  0   ",
                 "    11 1   0"};
                 */
                 
    int flag=0;
	solveSudoku(0,0,n1,s1,flag);
	//printSudoku(n,s);
	return 0;
}
