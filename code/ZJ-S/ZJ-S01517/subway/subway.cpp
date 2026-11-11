#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500001;
const ll INF=1e18;
struct Su{
	int id;
	ll ti;
};
int c,n,m,d,q,x,y;
int walk[N];
bool flag[501];
ll ans,mi;
ll len[501];
vector<Su> sub[501];
vector<Su> sta[N];
void dfs(int pl,int ed,ll sum,int line){
	if(pl==ed){
		mi=min(mi,sum);
		return;
	}
	for(int i=0;i<sta[pl].size();i++){
		int cl=sta[pl][i].id;
		if(cl==line&&pl!=x)continue;
		for(int j=0;j<sub[cl].size();j++){
			int to=sub[cl][j].id;
			if(to==pl)continue;
			ll t;
			for(int k=0;k<sta[to].size();k++)if(sta[to][k].id==cl)t=sta[to][k].ti;
			dfs(to,ed,sum+sta[pl][i].ti+t,cl);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> walk[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int id,ti;
			cin >> id >> ti;
			sub[i].push_back({id,ti});
			sta[id].push_back({i,ti});
		}
	}
	while(q--){
		cin >> x >> y;
		ans=INF;
		for(int i=0;i<sta[x].size();i++){
			mi=INF;
			dfs(x,y,0,sta[x][i].id);
			ans=min(ans,mi);
		}
		cout << ans+walk[x]+walk[y] << "\n";
	}
}
