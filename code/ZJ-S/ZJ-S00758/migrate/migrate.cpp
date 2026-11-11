#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace TEST_1_6{
	const int N=305;
	int n,d;
	int x[N];
	int dis[N][N],cnt[N][N];
	void Solve(){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i==j) dis[i][i]=0,cnt[i][i]=1;
				else dis[i][j]=1e18,cnt[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(x[j]-x[i]<=d)
					dis[i][j]=dis[j][i]=1,cnt[i][j]=cnt[j][i]=1;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i-j&&j-k&&k-i)
						dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		for(int k=1;k<=n;k++)
			for(int len=1;len<=n;len++)
				for(int i=1,j=len;j<=n;i++,j++)
					if(i-j&&j-k&&k-i)
						if(dis[i][j]==dis[i][k]+dis[k][j])
							cnt[i][j]+=cnt[i][k]*cnt[k][j];
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2){
					ans++;
				}
		cout<<ans<<"\n";
	}
}
namespace TEST_11_12{
	int n,d;
	void Solve(){
		int _;
		cin>>n>>d;
		if(n==1){
			cout<<"0\n";
			return;
		}
		int x=0,y=0;
		for(int i=1;i<=n;i++){
			cin>>_;
			if(i==1) x=_;
			else if(i==2) y=_; 
		}
		d/=y-x;
		cout<<((d>=2)?max(0ll,n-2*d+1):0)<<endl;
	}
}
namespace TEST_13_14{
	const int N=1e6+5;
	int n,d;
	int x[N],l[N],r[N];
	int sum[N];
	void Solve(){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			r[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
			l[i]=lower_bound(x+1,x+n+1,x[i]-d)-x;
			sum[l[i]]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=sum[r[i]-1];
			if(l[r[i]]==r[i]-1) ans--;
		}
		cout<<ans;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate5.in","r",stdin);
//	freopen("migrate5.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,T; cin>>c>>T;
	while(T--){
		if(1<=c&&c<=6) TEST_1_6::Solve();
		if(11<=c&&c<=12) TEST_11_12::Solve(); 
		if(13<=c&&c<=14) TEST_13_14::Solve();
	}
	return 0;
}
//40pts
