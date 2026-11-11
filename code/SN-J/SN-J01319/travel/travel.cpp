#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,c;
	char b[2],d[2];
	int w=0,y=0;
	cin>>a;
	for(int i=0;i<=2;i++)
	{
	    cin>>b[i];	
	}
	cin>>c;
	for(int i=0;i<=2;i++)
	{
	    cin>>d[i];	
	}
    if(a==c)
    {
    	cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(d[0]==b[0]&&d[1]==b[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0; 
	}
	if(d[2]=='A'||d[2]=='B'||d[2]=='C')
	{
	    w=1;    	
	}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')
	{
	    y=1;    	
	}
	if(y!=w)
	{
	   cout<<"00";
	}
	else
	{
		cout<<"1";
	}
	if(b[2]=='B'||d[2]=='B')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
