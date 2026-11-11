#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,c[100005],maxt;
string s,x;
char ch;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		c[i]=a;
		cin>>ch;
		for(int j=1;j<=a;j++)
			s+=ch;	
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		maxt=min(c[1],c[2]);
		cout<<maxt;
		return 0;
	}
	int len=s.size();
	for(int i=1;i<=len;i++)
		if(s[0]==s[i])
		{
			cout<<0;
			return 0;
		}
	return 0; 
}
