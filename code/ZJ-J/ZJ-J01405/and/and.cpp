#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+10;
int n,m,a[N],f[N],x[N][N];
int dfs(int c,int sum)
{
	if(x[c][sum]!=-1) return x[c][sum];
	int maxn=0;
	if(sum==0)
	{
		return c;
	}
	for(int i=1;i<=n;++i)
	{
		if(!f[i])
		{
			f[i]=1;
			maxn=max(dfs(c&a[i],sum-1),maxn);
			f[i]=0;
		}
	}
	return x[c][sum]=maxn;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	memset(x,-1,sizeof(x));
	int maxn=0;
	for(int i=1;i<=n;++i)
	{
		f[i]=1;
		maxn=max(maxn,dfs(a[i],m-1));
	}
	cout<<maxn;
	return 0;
}

