#include <bits/stdc++.h>
using namespace std;
using lnt = long long;
/*===================*/
const int N=510,M=5e5+10;
int n,m,d,q,w[M],t[N][M],a[N][M],k[M];
/*===================*/
lnt ans=0; 
bool vis[M];
void dfs(int s,int goal,lnt res,int from,int id){
	bool _abiongjhijk=0;
	int posi=-1;
	for (int j=1;j<=k[id];j++){
		if (a[id][j]==s){
			_abiongjhijk=1;
			posi=j;
		}
	}
	if (_abiongjhijk==0){
		return ;
	}
	if (s==goal){
		ans=min(ans,res);
		return ;
	}
	for (int i=1;i<=n;i++){
		if (i==id){
			if (posi!=1 && a[i][posi-1]!=from){
				dfs(a[i][posi-1],goal,res,s,id);
			}if (posi!=k[i] && a[i][posi+1]!=from){
				dfs(a[i][posi+1],goal,res,s,id);
			}
			continue;
		}
		for (int j=1;j<=k[i];j++){
			if (a[i][j]==s){
				if (j!=1 && a[i][j-1]!=from && !vis[a[i][j-1]]){
					vis[a[i][j-1]]=1;
					dfs(a[i][j-1],goal,res+t[i][j]+t[id][posi],s,i);
					vis[a[i][j-1]]=0;
				}if (j!=k[i] && a[i][j+1]!=from && !vis[a[i][j+1]]){
					vis[a[i][j+1]]=1;
					dfs(a[i][j+1],goal,res+t[i][j]+t[id][posi],s,i);
					vis[a[i][j+1]]=0;
				}
			}
		}
	}
}
/*===================*/
void solve(void){
	int c;cin >> c;
	cin >> n >> m >> d >> q;
	for (int i=1;i<=n;i++){
		cin >> w[i];
	}
	for (int i=1;i<=m;i++){
		cin >> k[i];
		for (int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		ans=0;
		for (int j=1;j<=n;i++){
			dfs(x,y,0,x,j);
		}
		cout << ans+w[x]+w[y] << "\n";
	}
}
/*===================*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T = 1; //cin >> T;
	while(T--) solve();
	return 0;
}
