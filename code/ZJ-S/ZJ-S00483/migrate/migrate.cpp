#include <bits/stdc++.h>
#define int long long
#define INF 0x7f7f7f7f7f7f7f7f
using namespace std;

int dis[5010][5010];
int cnt[5010][5010];
int a[5010];

void solve(){
	
	int n, d;
	cin >> n >> d;
	
	memset(dis,0x7f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
		dis[i][i]=0;
		cnt[i][i]=1;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(i==j)continue;
			if(abs(a[i]-a[j])>d)break;
			dis[i][j]=dis[j][i]=1;
			cnt[i][j]=cnt[j][i]=1;
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j || i==k || j==k)continue;
				if(dis[i][k]==INF || dis[k][j]==INF)continue;
				if(dis[i][j]==dis[i][k]+dis[k][j]){
					cnt[i][j]=min(cnt[i][j]+cnt[i][k]*cnt[k][j],3ll);
				}
				else if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					cnt[i][j]=min(cnt[i][k]*cnt[k][j],3ll);
				}
			}
		}
	}
	
	int ans=0;
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2)ans++;
		}
	}
	
	cout << ans << endl;
	
	return ;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int c, t;
	cin >> c >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}

