#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	bool f=true;
	for(int i=0;i<b.size()-1;i++)
	{
		if(b[i]!=d[i])
		{
			f=false;
		}
	}
	if(!f)
	{
		cout<<"1000";
		return 0;
	}
	int j=b.size()-1,k=d.size()-1;
	if((b[j]=='A'||b[j]=='B'||b[j]=='C')&&(d[k]=='D'||d[k]=='E'))
	{
		cout<<"1100";
		return 0;
	}
	if((b[j]=='A'&&d[k]=='C')||(b[j]=='C'&&d[k]=='A'))
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
 } 
