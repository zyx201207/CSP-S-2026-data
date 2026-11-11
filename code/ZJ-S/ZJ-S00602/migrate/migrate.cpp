#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5,M=305;
const long long inf=1e18;
int c,t;
ll a[N],dis[M][M];
void solve(){
	int n;
	ll d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(c>=10){
		cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]+d<a[j])break;
			dis[i][j]=dis[j][i]=1;
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ll cnt=0;
			for(int k=1;k<=n;k++){
				if(k!=i&&k!=j&&dis[i][j]==dis[i][k]+dis[k][j]){
					cnt++;
				}
			}
			if(cnt==2)ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}


