#include<bits/stdc++.h> 
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	string p1=s2.substr(0,2);
	string p2=s4.substr(0,2);
	char c2=s2[s2.length()-1];
	char c4=s4[s4.length()-1];
	if((p1==p2)&&(s1==s3))
	{
	   cout<<1;
	   if((c2<='C'&&c4<='C')||(c2>'C'&&c4>'C'))
	   {
	        cout<<1;	
	   }
	   else
	   {
	   	    cout<<0;
	   }
	}
	else
	{
		cout<<"00";
	}
	if((abs(c4-c2)==1)&&(s1==s3)&&(p1==p2))
	{
		if((c2=='C'&&c4=='D')||(c2=='D'&&c4=='C'))
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
}
