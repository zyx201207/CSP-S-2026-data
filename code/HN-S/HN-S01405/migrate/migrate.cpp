#include<bits/stdc++.h>
using gg = long long;
using namespace std;

const gg N = 2e3+5;

gg n,a[N],d,t,c,minn,ans;
bool vis[N];
struct infom{
	gg dist=2e18+5,cnt=0;
}ds[N][N];

void dfs(gg start,gg pos,gg step){
	if(ds[start][pos].dist < step){
		ds[start][pos].dist = step;
		ds[start][pos].cnt = 1;
	}
	else if(ds[start][pos].dist == step) ++ds[start][pos].cnt;
	for(gg i = -d;i <= d;++i){
		if(pos + d <= n && pos + d >= 1){
			if(!vis[pos + d]){
				vis[pos + d] = true;
				dfs(start,pos + d,step + 1);
				vis[pos + d] = false;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> t;
	while(t--){
		ans = 0;
		minn = 2e18+5;
		cin >> n >> d;
		for(gg i = 1;i <= n;++i){
			for(gg j = 1;j <= n;++j){
				ds[i][j].dist = 2e18+5;
				ds[i][j].cnt = 0;
			}
		}
		for(gg i = 1;i <= n;++i){
			cin >> a[i];
		}
		for(gg i = 1;i <= n;++i) dfs(i,i,0);
		for(gg i = 1;i <= n;++i){
			for(gg j = 1;j <= n;++j){
				if(i == j)continue;
				if(minn > ds[i][j].dist){
					ans = 0;
					minn = ds[i][j].dist;
					if(ds[i][j].cnt == 2) ans++;
				}else if(minn == ds[i][j].dist)
					if(ds[i][j].cnt == 2) ans++;
			}
		}
		cout << ans;
	}
	
	return 0;
}
