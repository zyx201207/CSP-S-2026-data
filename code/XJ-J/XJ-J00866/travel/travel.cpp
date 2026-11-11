#include<bits/stdc++.h>
using namespace std;
long long int i,j;
char c1,c2,s1[10],s2[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(i=1;i<=10;i++)
    cin>>c1>>s1[i]>>c2>>s2[i];
   if(c1==c2)
   {
   	    cout<<1;
   	    for(i=1;i<=5;i++)
   	     {
   		if(s1[i]==s2[i]&&s1[i]=="A"&&s2[i]=="B"||s1[i]=="B"&&s2[i]=="C"||s1[i]=="D"&&s2[i]=="F"||s2[i]=="F"&&s1[i]=="D"||s2[i]=="A"&&s1[i]=="B"||s1[i]=="A"&&s2[i]=="C"||s2[i]=="C"&&s1[i]=="A"||s2[i]=="C"&&s1[i]=="B")
   		{
   			{
   				cout<<1;
   			else
   			cout<<0;
			   }
   			
   			if(s1[i]=="A"&&s2[i]=="B"||s1[i]=="B"&&s2[i]=="C"||s2[i]=="A"&&s1[i]=="B"||s1[i]=="A"&&s2[i]=="C"||s2[i]=="C"&&s1[i]=="A"||s2[i]=="C"&&s1[i]=="B"||s1[i]=="D"&&s2[i]=="F"||s2[i]=="F"&&s1[i]=="D")
   			{
			cout<<1;
   			else
   			cout<<0;
			}
   			
   			if(s1[i]=="A"&&s2[i]=="B"||s1[i]=="B"&&s2[i]=="C"||s2[i]=="A"&&s1[i]=="B"||s2[i]=="C"&&s1[i]=="B"||s1[i]=="D"&&s2[i]=="F"||s2[i]=="F"&&s1[i]=="D")
   			{
   			cout<<1;
   			else
   			cout<<0;
		    }
		}
	  }
   }
   return 0;
}
