#include<bits/stdc++.h>
using namespace std;
int main()
{     
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    char a[20],b[20];
    string A1,B1,B2,A2,t1;
    int n,i,k;

	cin>>B1>>A1>>B2>>A2;
	if(B1!=B2)
	{
	   cout<<0;
    }
	else
	{
	   cout<<1;
    }
	if(A1[A1.size()-3]!=A2[A2.size()-3]&&A1[A1.size()-2]!=A2[A2.size()-2]||A1[A1.size()-3]==A2[A2.size()-3]&&A1[A1.size()-2]!=A2[A2.size()-2]||A1[A1.size()-3]!=A2[A2.size()-3]&&A1[A1.size()-2]==A2[A2.size()-2])
	{
       cout<<0;
    }
	else
    {
	   cout<<1;
    }
	if(A1[A1.size()-1]=='A'&&A2[A2.size()-1]=='A'||A1[A1.size()-1]=='A'&&A2[A2.size()-1]=='B'||A1[A1.size()-1]=='A'&&A2[A2.size()-1]=='C'||A1[A1.size()-1]=='B'&&A2[A2.size()-1]=='A'||A1[A1.size()-1]=='B'&&A2[A2.size()-1]=='B'||A1[A1.size()-1]=='B'&&A2[A2.size()-1]=='C'||A1[A1.size()-1]=='C'&&A2[A2.size()-1]=='A'||A1[A1.size()-1]=='C'&&A2[A2.size()-1]=='B'||A1[A1.size()-1]=='C'&&A2[A2.size()-1]=='C')
	{
	   cout<<1;
    }
	else
	{
	   cout<<0;
	}
	if(A1[A1.size()-1]==A2[A2.size()-1]+1||A1[A1.size()-1]==A2[A2.size()-1]-1)
	{
	   cout<<1;
    }
	else
	{
	   cout<<0;
    }
	return 0;
	}
