#include<bits/stdc++.h>
using namespace std;
long long C,T;
long long n,d;
long long ans;
long long x[2000005];
long long t[2000005];
long long pos[2000005];
long long num[2000005][2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(long long i=1;i<=n;i++) cin>>x[i];
		ans=0;
		for(long long i=1;i<=n;i++)
		{
			pos[i]=0;
			num[i][1]=num[i][2]=0;
		}
		for(long long i=1;i<=n;i++)
		{
			t[i]=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
		}
		for(long long i=n;i>=1;i--)
		{
			pos[t[i]]=i;
			num[i][1]+=t[i]-t[i-1];
			if(t[i]==i) continue;
			if(t[i]-pos[t[t[i]]]+1==1)
			{
				num[i][1]+=num[t[i]][1];
				if(t[i]-1>i)
				{
					if(t[i]-1-pos[t[t[i]-1]]+1==1)
					{
						num[i][2]+=t[t[i]-1]-t[t[i]-2];
					}
				}
				if(t[i]==t[t[i]-1])
				{
					num[i][2]+=num[t[i]][2];
				}
			}
			else if(t[i]-pos[t[t[i]]]+1==2)
			{
				if(t[i]-1>i)
				{
					num[i][2]+=num[t[i]-1][1];
				}
			}
		}
		for(long long i=1;i<=n;i++)
		{
			ans+=num[i][2];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
