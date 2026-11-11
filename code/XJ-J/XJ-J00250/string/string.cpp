#include<bits/stdc++.h>
using namespace std;
int n,m,b=0,r,mx=0;
string s;
char a;
int main()
{

freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>n;
		cin>>a;
		for(int j=1;j<=n;j++)
		{
			s[b]=a;
			b++;
		}
	}
	r=b-1;
	for(int i=0;i<b/2;i++)
	{
	
		if(s[i]!=s[r]-i)
		{
			mx++;
		}
	}
	cout<<mx;
} 


