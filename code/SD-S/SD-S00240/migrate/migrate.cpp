#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,LN=310;
int c,t;
int n;
long long x[N],d;
int dis[LN][LN];
long long cnt[LN][LN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		long long ans=0;
		for(int i=1;i<=n;i++)cin >> x[i];
		memset(dis,0x3f,sizeof(dis));memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i] <= d){
//					cout << i << ' ' << j << '\n';
					dis[i][j]=dis[j][i]=1;
					cnt[i][j]=cnt[j][i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(dis[i][k]+dis[k][j] < dis[i][j]){
						dis[i][j]=dis[i][k]+dis[k][j];
						cnt[i][j]=cnt[i][k]*cnt[k][j];
					}else if(dis[i][k]+dis[k][j] == dis[i][j]){
						cnt[i][j]+=cnt[i][k]*cnt[k][j];
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
				if(cnt[i][j]==2)ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
