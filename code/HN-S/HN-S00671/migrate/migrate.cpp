#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e6+10,INF=1e18;
struct P{
	int u,st;
};
int c,t,n,d,a[N],f[1005][1005],cs[1005][1005],sim[N],vis[1005][1005];
vector<int>g[N];
void MAIN(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					g[i].push_back(j);
				}else{
					j=n+1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=INF;
			}
			f[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			for(auto e:g[i]){
				f[i][e]=f[e][i]=1;
			}
		}
		for(int k=1;k<=n;k++){
		 	for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(k<=i||k>=j){
						continue;
					}
					if(f[i][k]+f[k][j]<f[i][j]){
						f[i][j]=f[i][k]+f[k][j];
						cs[i][j]=1;
					}else if(f[i][k]+f[k][j]==f[i][j]){
						f[i][j]=f[i][k]+f[k][j];
						cs[i][j]++;
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(cs[i][j]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		MAIN();
	}
	return 0;
}
