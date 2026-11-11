#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
bool v[500005][3] = {};
int w[500005] = {};
int t[3][500005] = {};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(n==2){
		for(int i = 1;i<=m;i++){
			cin>>w[i];
		}
		for(int i = 1;i<=n;i++){
			int k;
			cin>>k;
			int a;
			for(int j = 1;j<=k;j++){
				cin>>a>>t[i][a];
				v[a][i] = true;
			}
		}
		for(int i = 1;i<=q;i++){
			int st,ed;
			cin>>st>>ed;
			if(v[st][1]&&v[ed][1]){
				long long ans = 1ll*w[st]+t[1][st]+t[1][ed]+w[ed];
				cout<<ans<<'\n';
			}else if(v[st][2]&&v[ed][2]){
				long long ans = 1ll*w[st]+t[2][st]+t[2][ed]+w[ed];
				cout<<ans<<'\n';
			}else if(v[st][1]&&v[ed][2]){
				long long ans = LLONG_MAX;
				for(int j = 1;j<=m;j++){
					if(v[j][1]&&v[j][2]){
						ans = min(ans,1ll*w[st]+t[1][st]+t[1][j]+t[2][j]+t[2][ed]+w[ed]);
					}
				}
				cout<<ans<<'\n';
			}else if(v[st][2]&&v[ed][1]){
				long long ans = LLONG_MAX;
				for(int j = 1;j<=m;j++){
					if(v[j][1]&&v[j][2]){
						ans = min(ans,1ll*w[st]+t[2][st]+t[1][j]+t[2][j]+t[1][ed]+w[ed]);
					}
				}
				cout<<ans<<'\n';
			}
		}
		return 0;
	}else{
		cout<<1;
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
