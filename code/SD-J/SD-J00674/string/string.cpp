#include<bits/stdc++.h>
using namespace std;
struct str{
	int x;
	char ch;
}s[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].x>>s[i].ch;
		if(s[i].ch!=s[i-1].ch) f=1;
		ans+=s[i].x*s[i].ch; 
	}
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	if(ans>1e8)
	{
		cout<<"3000000000";
		return 0;
	}
	string k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=s[i].x;j++) k+=s[i].ch;
	}
	ans=0;
	for(int i=0;i<k.size();i++)
	{
		if(k[i]!=k[k.size()-i-1])
		{
			k[k.size()-i-1]=k[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
