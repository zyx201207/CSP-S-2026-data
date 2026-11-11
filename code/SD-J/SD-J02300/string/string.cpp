#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node
{
	int a;
	char c;
}b[200005];
int ans;
string s;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int f=0,t=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i].a>>b[i].c;
		if(i>=2&&b[i].c!=b[i-1].c)
		{
			t=1;
		}
		if(b[i].a>=2)
		{
			f=1;
		}
	}
	if(f==0)
	{
		for(int i=1;i<=n/2;i++)
		{
			if(b[i].a!=b[n-i+1].a)
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(t==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n/2;i++)
	{
		if(b[i].c!=b[n-i+1].c)
		{
			ans+=max(b[i].a,b[n-i+1].a);
		}
	}
	cout<<ans;
	return 0;
}

