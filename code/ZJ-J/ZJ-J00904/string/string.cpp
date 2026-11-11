#include<bits/stdc++.h>
using namespace std;
int n,l,ans;
string s;
struct node{
	int a;
	char c;
};
node m[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;

    	 
	for(int i=1;i<=n;i++)
	{
		cin>>m[i].a >>m[i].c;
	}
	if(n==1)
	{
	  	cout<<0;
	  	return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m[i].a;j++)
		{
			s+=m[i].c;
		}
	}
	l=s.size();
	for(int i=0;i<l/2;i++)
	{
		if(s[i]!=s[l-1-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
