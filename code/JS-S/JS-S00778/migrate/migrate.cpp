#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
const int siz=2e6+10;
int a[siz],lef[siz],rig[siz],kda[siz],kdb[siz],knd[siz],sua[siz],sub[siz],suc[siz],ta[siz],tb[siz],wrk[siz];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	int _,t,cf=0;
	cin>>_>>t;
	while(t--)
	{
		cf++;
		int n,k,ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		a[0]=-4e18,a[n+1]=4e18;
		int tp;
		tp=0;for(int i=1;i<=n;i++){while(a[tp+1]-a[i]<=k)tp++;rig[i]=tp;}
		tp=n+1;for(int i=n;i>=1;i--){while(a[i]-a[tp-1]<=k)tp--;lef[i]=tp;}
		for(int i=1;i<=n;i++)
		{
			kda[lef[i]]++;
			if(lef[i]!=i)kdb[lef[i]+1]++;
			if(i==1||rig[i-1]!=rig[i]){knd[i]=1;continue;}
			if(i==2||rig[i-2]!=rig[i]){knd[i]=2;continue;}
			knd[i]=3;
		}
		//for(int i=1;i<=n;i++)cerr<<knd[i]<<' ';cerr<<"\n";
		// for(int i=1;i<=n;i++)cerr<<lef[i]<<' ';cerr<<"\n";
		// for(int i=1;i<=n;i++)cerr<<rig[i]<<' ';cerr<<"\n";
		//for(int i=1;i<=n;i++)cerr<<kda[i]<<' ';cerr<<"\n";
		//for(int i=1;i<=n;i++)cerr<<kdb[i]<<' ';cerr<<"\n";
		for(int i=n-1;i>=1;i--)
		{
			int nx=rig[i];wrk[i]=min(knd[nx],nx-i);
			if(min(knd[nx],nx-i)==3||rig[i]==i){sua[i]=sub[i]=suc[i]=0;continue;}
			else if(min(knd[nx],nx-i)==2||tb[nx]&&wrk[nx]==2)
				suc[i]=sua[nx],sua[i]=kda[nx],sub[i]=kdb[nx],ta[i]=tb[i]=(i!=1&&rig[i-1]>=nx-1&&i!=nx-1);
			else suc[i]=suc[nx],sub[i]=(ta[nx]==0?sub[nx]:0)+kdb[nx]-(i==nx-1&&lef[nx]==i),sua[i]=sua[nx]+kda[nx],ta[i]=(i!=1&&rig[i-1]>=nx-1&&i!=nx-1);
			ans+=sub[i]+suc[i];//sub[i]+=(i==nx-1);
		//	cerr<<ans<<' '<<i<<' '<<nx<<' '<<sua[i]<<' '<<sub[i]<<' '<<suc[i]<<' '<<ta[i]<<' '<<lef[nx]<<' '<<wrk[nx]<<'\n';
		//	if(cf==1&&i>=99990)cerr<<lef[i]<<' '<<rig[i]<<' '<<rig[i+1]<<' '<<a[i]<<'\n';
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)kda[i]=knd[i]=kdb[i]=sua[i]=sub[i]=suc[i]=lef[i]=rig[i]=ta[i]=tb[i]=0;
	}
	return 0;
}
//>>>>>>>>replace