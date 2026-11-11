#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long x[2000005];
long long sum[2000005];
long long cnt[2000005];
long long bnt[2000005];
long long ans;
bool check(int s,int t)
{
	for(int i=s;i<=t;i++)sum[i]=1e18,cnt[i]=0,bnt[i]=0;
	sum[s]=1,cnt[s]=1,bnt[s]=1,bnt[s-1]=0;
	for(int i=s+1;i<=t;i++)
	{
		int l=lower_bound(x+s,x+i,x[i]-d)-x;
		if(l==i)break;
		sum[i]=sum[l]+1;
		int r=upper_bound(sum+s,sum+i,sum[l])-sum;
		cnt[i]=bnt[r-1]-bnt[l-1];
		bnt[i]=bnt[i-1]+cnt[i];
	}
	return cnt[t]==2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				if(check(i,j))ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
