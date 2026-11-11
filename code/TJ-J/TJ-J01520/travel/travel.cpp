#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2,r1,m;
	cin>>c1>>c2>>s1>>s2>>r1>>m;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>i;
	if(c1=c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if((c1=c2 ) || (s1=r1) || (s2=r1))
	{
		cout<<"1";
	}	
	else
	{
		cout<<"0";
	}
	if((c1=c2 )|| (s1=r1 )|| (s2=r1) || (s1=m) || (s2=m))
	{
		cout<<"1";     
	}
	else
	{
		cout<<"0";
	}
	if( (s1!=s2) || (s1+=s2) )
	{
		cout<<"1";
	}
	else
	{
		cout<<"0"; 
	}
}
	return 0;
 } 
