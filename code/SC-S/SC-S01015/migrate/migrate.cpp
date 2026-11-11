#include<bits/stdc++.h>
using namespace std;
int c,t;
const int N=1e7+5;
const int INF=100000;
int a[N];
int f[10005][10005];
int p[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=10000;i++){
			for(int j=1;j<=10000;j++){
				f[i][j]=INF;
			}
		}
		int ans;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
					p[f[i][j]]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(p[f[i][j]]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}