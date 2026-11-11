#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 500500,inf = 1e18;
ll dep[maxn];
ll mp[1010][1010];
struct station{
	ll id,val;
};
vector<station> sub[500500];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll c,n,m,d,q,i,j,u,v,w,op,x,y,k;
	bool spa = 1;
	cin>>c>>n>>m>>d>>q;
	for(i = 1;i <= m;i++){
		cin>>dep[i];
	}
	for(i = 1;i <= n;i++)
		for(j = 1;j <= n;j++)
			if(i != j) mp[i][j] = inf;
	for(i = 1;i <= n;i++){
		cin>>op;
		for(j = 1;j <= op;j++){
			cin>>v>>w;
			sub[v].push_back((station){i,w});
			for(k = 0;k < sub[v].size();k++){
				mp[i][sub[v][k].id] = mp[sub[v][k].id][i] = min(mp[sub[v][k].id][i],w + sub[v][k].val);
			}
		}
	}
	for(k = 1;k <= n;k++)
		for(i = 1;i <= n;i++)
			for(j = 1;j <= n;j++)
				if(mp[i][k] + mp[k][j] < mp[i][j])
					mp[i][j] = mp[i][k] + mp[k][j];
	while(q--){
		cin>>x>>y;
		ll ans = inf;
		for(i = 0;i < sub[x].size();i++){
			for(j = 0;j < sub[y].size();j++){
				ll res = sub[x][i].val + sub[y][j].val + mp[sub[x][i].id][sub[y][j].id];
				ans = min(ans,res);
			}
		}
		cout<<ans + dep[x] + dep[y]<<"\n";
	}
	return 0;
}
