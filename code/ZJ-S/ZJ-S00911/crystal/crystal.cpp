#include<bits/stdc++.h>
using namespace std;
#define int long long
const int slen=5e5+10,maxv=1e12;
long long a[slen],all[slen];
long long dp[slen];int n,m;
int truthmid=0;
int ck(int mid)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=ans+abs(mid-a[i]);
	}
	return ans;
}
int dfs(int node,int deep,int num)
{
	if(deep<=0)
	{
		//cout<<num<<"  "<<deep<<endl;
		if(deep==-1)	return num;
		else	return -1;
	}
	int ans=num;
	for(int j=node+1;j<=n;j++)
	{
		int v=abs(a[truthmid]-a[j]);
		if(v>m)	continue;
		//cout<<j<<" ";
		ans=max(ans,dfs(j,deep-v,num+1));
	}
	//cout<<endl;
	return ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n;int last=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		int u=ck(mid);
		//cout<<l<<"  "<<r<<"  "<<u<<endl;
		if(u>last)
		{
			r=mid-1;
			if(last==0)	truthmid=mid;
		}
		else
		{
			l=mid+1;
			truthmid=mid;
		}
		if(last!=0)	last=min(last,u);
		else	last=u;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[truthmid])	ans++;
		int u=abs(a[truthmid]-a[i]);
		if(u>m)	continue;
		//cout<<i<<" ";
		ans=max(ans,dfs(i,m-u,1));
	}
	cout<<ans;
	return 0;
}