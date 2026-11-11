#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10,inf=1e18;
int a[N];
int c,t;
const int M=305;
int dist[M][M];
inline int solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2) return 0ll;
	if(c==11||c==12){
		int cnt=a[2]-a[1];
		int maxn=d/cnt;
		if(maxn<=1)	return 0ll;
		return max(n-2*maxn+1,0ll);
	}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=inf;
			}
		}
		int ppp=0ll;
		for(int i=1;i<=n;i++){
			dist[i][i]=0ll;
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d) dist[i][j]=dist[j][i]=1;
				else{
					for(int k=j+1;k<i;k++){
						dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
					}
					int cnt=0ll;
					for(int k=j+1;k<i;k++){
						if(dist[i][k]+dist[k][j]==dist[i][j]&&dist[i][j]!=inf) cnt++;
					}
					dist[j][i]=dist[i][j];
					if(cnt==2){
						//cout<<i<<" "<<j<<'\n';
						ppp++;
					}
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				cout<<dist[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
		return ppp;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cout<<solve()<<'\n';
	}
}