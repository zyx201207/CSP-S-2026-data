#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m;
int n;
long long c[N],d[N];
unsigned long long s[N];//s[i]:前i个补齐的最小花费 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=2;i<=n;i++)
	{
		d[i]=c[i]-c[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		s[i]=s[i-1]+d[i]*(i-1);
	}
	long long ans=-1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>m)
		{
			ans=i-1;
			break;
		}
	}
	if(ans==-1) ans=n;
	cout<<ans<<'\n';
	return 0;
}
