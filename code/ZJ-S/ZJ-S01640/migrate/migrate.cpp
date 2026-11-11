#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[2000005],nxt[2000005],pre[2000005],lsz[2000005],rsz[2000005],s[2000005];
void test()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int p=0;
	for(int i=1;i<=n;i++)
	{
		while(p<n&&a[p+1]-a[i]<=d)
			p++;
		nxt[i]=p;
	}
	p=n+1;
	for(int i=n;i>=1;i--)
	{
		while(p>1&&a[i]-a[p-1]<=d)
			p--;
		pre[i]=p;
	}
	for(int i=1;i<=n;i++)
		lsz[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(nxt[i]>i&&pre[nxt[i]]==i)
			lsz[nxt[i]]+=lsz[i];
		if(nxt[i]>i&&pre[nxt[i]]<=i)
			lsz[nxt[i]]++;
		lsz[i]++;
	}
	for(int i=1;i<=n;i++)
		rsz[i]=0;
	for(int i=n;i>=1;i--)
	{
		if(pre[i]<i&&nxt[pre[i]]==i)
			rsz[pre[i]]+=rsz[i];
		if(pre[i]<i&&nxt[pre[i]]>=i)
			rsz[pre[i]]++;
		rsz[i]++;
	}
	for(int i=1;i<=n;i++)
		s[i]=0;
	for(int i=1;i<=n;i++)
		s[pre[i]]++;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(nxt[i]>i+1&&pre[nxt[i]-1]==i)
		{
			int t=s[nxt[i]-1];
			if(pre[nxt[i]]==nxt[i]-1)
				t--;
			if(nxt[nxt[i]]>nxt[i]&&pre[nxt[nxt[i]]]==nxt[i]-1)
				t--,ans+=rsz[nxt[nxt[i]]]*lsz[i];
			ans+=t*lsz[i];
			// cout<<i<<" "<<ans<<" "<<lsz[i]<<" "<<rsz[i]<<"\n";
		}
		if(nxt[i]>i+1&&pre[nxt[i]-1]<i)
		{
			int t=s[nxt[i]-1];
			if(pre[nxt[i]]==nxt[i]-1)
				t--;
			if(nxt[nxt[i]]>nxt[i]&&pre[nxt[nxt[i]]]==nxt[i]-1)
				t--,ans+=rsz[nxt[nxt[i]]];
			ans+=t;
			// cout<<i<<"#"<<ans<<" "<<lsz[i]<<" "<<rsz[i]<<"\n";
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
		test();
}