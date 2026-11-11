#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],cf[N],sum[N];
unsigned long long m;
ll n,maxn;
bool vis[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		cf[i]=a[i]-a[i-1];
//		cout<<cf[i]<<" ";
	}
//	cout<<"\n";
	for(int i=1;i<=n;i++)
	{
		sum[i]=cf[i]+sum[i-1];
//		cout<<sum[i]<<" ";
	}
	ll l=1,r=1;
	ll now=0;unsigned long long cnt=0;
	while(r<=n)
	{
		while(cnt<=m&&r<=n)
		{
			if(!vis[r])
			{
				cnt+=cf[r]*now;
				vis[r]=1;
			}
//			cout<<cnt<<"\n";
			if(cnt<=m) maxn=max(maxn,r-l+1);
			if(cnt>m) break;
			r++;
			now++;
		}
		cnt-=sum[r]-sum[l];
		now--;
		l++;
	}
	cout<<maxn;
	return 0;
}
