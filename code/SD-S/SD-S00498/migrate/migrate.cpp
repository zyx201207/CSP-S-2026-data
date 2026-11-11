#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7;
const int INF=1e18;
int c,t,X[N];
int dis[307][307],cnt[307][307];
void solve(){
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>X[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=INF,cnt[i][j]=0;
	for(int i=1;i<=n;i++) dis[i][i]=0,cnt[i][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j) continue;			
			if(abs(X[j]-X[i])<=d){
				dis[i][j]=dis[j][i]=1;
				cnt[i][j]=cnt[j][i]=1;
			}
		}
	}		
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=i+1;k<j;k++) dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=i+1;k<j;k++) if(dis[i][j]==dis[i][k]+dis[k][j]) cnt[i][j]+=cnt[i][k]*cnt[k][j];
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(cnt[i][j]==2) ans++;
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
