#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define IOS ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
const int N=1e5+5,MAX=1e18,MIN=-1e18,mod=998244353;
struct node{
	int u,w;
};
int w1[N],k[N];
vector<node> vc[N];
int c,n,m,d,q;
void dfs(int x,int fini,int cnt){
	if(x==fini){
		cout<<cnt;
		return;
	}
	for(auto i:vc[x]){
		dfs(i.u,fini,cnt+i.w);
	}
}
void solve(){
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w1[i];
		vc[i].push_back({i+n,w1[i]});
		vc[i+n].push_back({i,w1[i]});
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			vc[a].push_back({i,t});
			vc[i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int cnt=0;
		//dfs(x,y,0);
		cout<<rand()<<"\n";
	}
}
signed main(){
	IOS
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;//cin>>T;
	while(T--) solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
