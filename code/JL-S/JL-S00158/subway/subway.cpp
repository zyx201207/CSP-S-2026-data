#include<bits/stdc++.h>
using namespace std;
#define N 11110
int a[N],b[N];
int g[N],s[N],h[N];
int j[N],l[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
	cin>>a[i];
	}
	int o;
	cin>>o;
	int cnt;
	int sum;
	for(int i=1;i<=o;i++)
	{
	cin>>b[i]>>s[i];
	}
	int e;
	cin>>e;
	for(int i=1;i<=e;i++)
	{
	cin>>g[i]>>h[i];
	}
	for(int i=1;i<=q;i++)
	{
	cin>>j[i]>>l[i];
	cnt=j[i];
	sum=l[i];
	for(int i=1;i<=o;i++)
	{
	if(cnt==b[i])
	{
	ans+=s[i];
	}
	if(sum==s[i])
	{
	ans+=s[i];
	}
	}
		for(int i=1;i<=e;i++)
	{
	if(cnt==g[i])
	{
	ans+=h[i];
	}
	if(sum==g[i])
	{
	ans+=h[i];
	}
	}
	for(int i=1;i<=m;i++)
	{
	if(cnt==i)
	{
	ans+=a[i];
	}
	if(sum==i)
	{
	ans+=a[i];
	}
	}
	}
	cout<<ans<<endl;
	
	return 0;
}
