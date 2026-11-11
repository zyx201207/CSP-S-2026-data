#include <bits/stdc++.h> 
using namespace std;
long long c,t,n,d,x[2000005],dist[500][500],cnt[500][500][500],used[500][500];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c>>t;
	while (t--){
		cin >>n>>d;
		for (int i = 1;i <= n;i++){
			cin>>x[i];
		}
		if (n<=300){
			memset(dist,0x3f,sizeof(dist));
			for (int i = 1;i <= n;i++){
				for (int j = i+1;j <= n;j++){
					if (abs(x[i]-x[j])<=d){
						dist[i][j]=1;
						dist[j][i]=1;
					}
				}
			}
			memset(cnt,0,sizeof(cnt));
			for (int i = 1;i <= n;i++){
				for (int j=1;j <= n;j++){
					for (int k = 1;k <= n;k++){
						dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
						if (dist[j][k]==dist[j][i]+dist[i][k])cnt[j][k][dist[j][k]]++;
					}
				}
			}
			memset(used,0,sizeof(used));
			int ans=0;
			for (int u =1;u <= n;u++){
				for (int v = 1;v<=n;v++){
					if (used[v][u])continue;
					if (cnt[u][v][dist[u][v]]==2)ans++;
					used[u][v]=1;
				}
			}
			cout <<ans<<endl;
		}
		else cout <<0<<endl;
	}
	return 0;
}


