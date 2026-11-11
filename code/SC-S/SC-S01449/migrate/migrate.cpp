#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+5,M=5e3+5;
int n,d,a[N],R[N];
int dis[M][M],cnt[M][M];
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>a[i];
	int r=n;
	for(int i=n;i>=1;--i){
		while(n>i&&a[r]-a[i]>d)r--;
		R[i] = r;
	}
//	memset(dis,0x3f,sizeof dis);
//	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			dis[i][j]=1e18,cnt[i][j]=0;
		}
	}
	for(int i=n;i>=1;--i){
		dis[i][i] = 0;cnt[i][i]=1;
		for(int j=i+1;j<=R[i];++j)dis[i][j]=1,cnt[i][j]=1;
		for(int j=R[i]+1;j<=n;++j){
			dis[i][j]=dis[R[i]][j]+1;cnt[i][j]=cnt[R[i]][j];
			int p=R[i]-1;
			while(cnt[i][j]<=2&&p>i){
				if(dis[p][j]==dis[R[i]][j])cnt[i][j]+=cnt[p][j],p--;
				else break;
			}
		}
	}
	int ans = 0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j)ans+=(cnt[i][j]==2);
//		cout<<"I:"<<i<<" ";
//		for(int j=1+i;j<=n;++j){
//			if(cnt[i][j]==2)cout<<j<<" ";
//		}
//		cout<<"\n\n";
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--) solve();
	return 0;
}