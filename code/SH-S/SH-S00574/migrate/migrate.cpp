#include<bits/stdc++.h>
using namespace std;
//thinking:3:10~4:30 80min
//input>=10^6->cin instead of scanf!!!!!!!
long long a[2000011];
long long nxt[2000011];
long long pre[2000011];
long long hxl[2000011];
long long hxr[2000011];
long long l[2000011];
long long r[2000011];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=0;i<=n+1;i++)hxl[i]=hxr[i]=l[i]=r[i]=0;
		for(int i=1;i<=n;i++)nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		for(int i=1;i<=n;i++)pre[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
		//for(int i=1;i<=n;i++)cout<<nxt[i]<<" ";
		//cout<<"\n";
		//for(int i=1;i<=n;i++)cout<<pre[i]<<" ";
		//cout<<"\n";
		for(int i=1;i<=n;i++)
		{
			if(pre[i]!=i&&i!=nxt[pre[i]])r[pre[i]]++;
			if(nxt[i]!=i&&i!=pre[nxt[i]])l[nxt[i]]++;
		}
		//for(int i=1;i<=n;i++)cout<<f[i]<<" ";
		//cout<<"\n";
		//for(int i=1;i<=n;i++)cout<<g[i]<<" ";
		//cout<<"\n";
		l[0]=0,l[n+1]=0;
		r[0]=0,r[n+1]=0;
		for(int i=1;i<=n;i++)
		{
			if(pre[i]==i)continue;
			if(nxt[pre[i]]==i)l[i]+=l[pre[i]]+1;
		}
		for(int i=n;i>=1;i--)
		{
			if(nxt[i]==i)continue;
			if(pre[nxt[i]]==i)r[i]+=r[nxt[i]]+1;
		}
		for(int i=1;i<=n;i++)hxl[i]=l[i],hxr[i]=r[i];
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(pre[i+1]!=i+1&&i+1!=nxt[pre[i+1]]&&pre[i+1]==i)r[i]--;
			if(nxt[i]!=i&&i!=pre[nxt[i]]&&nxt[i]==i+1)l[i+1]--;
			if(nxt[pre[i+1]]==i+1&&pre[i+1]==i)r[i]-=hxr[i+1]+1;
			if(pre[nxt[i]]==i&&nxt[i]==i+1)l[i+1]-=hxl[i]+1;
			ans+=l[i+1]*r[i];
		}
		// case 1:pre&nxt
		for(int i=1;i<=n;i++)
		{
			if(nxt[i]==i)continue;
		}
		//for(int i=1;i<=n;i++)cout<<l[i]<<" ";
		//cout<<"\n";
		//for(int i=1;i<=n;i++)cout<<r[i]<<" ";
		//cout<<"\n";
		cout<<ans<<"\n";
	}
}
