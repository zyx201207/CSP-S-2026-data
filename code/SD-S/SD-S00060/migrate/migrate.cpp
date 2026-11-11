#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid ((l+r)>>1)
#define ls (rt*2)
#define rs (rt*2+1)
const int N=2e6+5;
const int INF=0x3f3f3f3f;
const int Mod=1e9+7;
int C;
int n,d;
int a[N];
int dis[N],cnt[N];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(C>=11&&C<=12)
	{
		int len=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]-a[1]<=d)
			{
				len=i;
				break;
			}
		}
		if(len<=2)cout<<0<<endl;
		else cout<<max(0ll,n-2*len+3)<<endl;
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)//出发点i 
		{
			for(int j=1;j<=n;j++)
			{
				dis[j]=cnt[j]=0;
			}
			int l=i;//最左可到达点 
			dis[i]=0;cnt[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				while(a[j]-a[l]>d)l++;
				if(l==j)
				{
					break;
				}
				dis[j]=dis[l]+1;
				int t=l;
				while(dis[t]+1==dis[j]&&t<j)
				{
					cnt[j]+=cnt[t];t++;
				} 
				if(cnt[j]==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;cin>>C>>T;
	while(T--)solve();
	return 0;
}
