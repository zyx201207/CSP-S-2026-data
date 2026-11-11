#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
const int MAX=1e9+7;
int a[N],dp[N],dn[N];//dn[i]表示到这个点最小的路径长度 
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T;cin>>C>>T;
	while(T--)
	{
		int n,d;int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(C>=1&&C<=6)
		{
			for(int _=1;_<=n;_++)
			{
				dp[_]=1;
				dn[_]=0;
				for(int v=_+1;v<=n;v++)dn[v]=MAX;
				int l=_;
				for(int i=_+1;i<=n;i++)
				{
					while(a[i]-a[l]>d)
					{
						l++;
					}
					for(int j=l;j<=i;j++)
					{
						if(dn[i]>dn[j]+1)
						{
							dn[i]=dn[j]+1;
							dp[i]=dp[j];
						}
						else if(dn[i]==dn[j]+1)
						{
							dp[i]+=dp[j];
						}
					}
				}
				for(int i=_;i<=n;i++)
				{
					if(dp[i]==2)ans++;
				}
				for(int i=1;i<=n;i++)
				{
					dp[i]=0;dn[i]=MAX;
				}
			}
			cout<<ans<<"\n";
		}
		else if(C>=11&&C<=12)
		{
			d=d/(a[2]-a[1]);
			if(d==1||d==0){
				cout<<0<<"\n";
				continue;
			}
			if(2*d<=n)
			{
				for(int i=1;i+(2*d)-1<=n;i++){
					ans+=(2*d*d-d-1);
				}
				ans+=(d*d+d-2)/2;
				cout<<ans<<"\n";
			}
			else if(2*d>n)
			{
				int k=2*d-n+2;
				ans=d*d+2*k*d+k*k+d+k;
				cout<<2*ans<<"\n";
			}
		}
	}
	return 0;
}

