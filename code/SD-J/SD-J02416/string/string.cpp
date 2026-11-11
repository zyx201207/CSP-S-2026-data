#include<bits/stdc++.h>
using namespace std;
struct str{
	long int x;
	char id;
};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,h=0,sa=0;
	cin>>n;
	str s[10000]={NULL};
	bool is=1;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].x;
		cin>>s[i].id;	
	}
	sa=s[0].id;
	for(int i=0;i<n;i++)
	{
		if(s[i].id!=sa)
		{
			is=0;
		}
	}
	if(is)
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<=n/2-1;i++)
	{
		if(s[i].id!=s[n-i-1].id)
		{
			h=h+s[n-i-1].x;
			s[n-i-1].id=s[i].id; 			
		}
		if(s[i].x!=s[n-i-1].x)
		{
			h=h+max(s[i].x,s[n-i-1].x)-min(s[i].x,s[n-i-1].x);
			s[n-i-1].x=s[i].x;
		}
	}
	cout<<h;
	return 0;
}
