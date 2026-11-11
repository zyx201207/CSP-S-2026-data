#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
const int INF=1e9;
int c,n,m,d,q;
int w[M];int st,ed;
bool vis[M];
struct node{
	vector<int> a,t;
}metro[N];
int ans=INF;
void dfs(int x,int tim,int lst){
	vis[x]=1;
	if(x==ed){
		ans=min(ans,tim);
		return ;
	}
	for(int i=1;i<=n;i++){
		bool f=0,nxt;
		for(auto &a:metro[i].a){
			if(x==a){
				nxt=a;
				f=1;
			}
		}
		if(f){
			for(auto &t:metro[i].t){
				if(x!=nxt&&!vis[nxt]){
					dfs(nxt,tim+t+lst,t);
				}
			}
		}
	}
}
int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			metro[i].a.push_back(x),metro[i].t.push_back(y);
		}
	}
	while(q--){
		cin>>st>>ed;
		ans=0;
		dfs(st,0,0);
		ans+=w[st]+w[ed];
		cout<<ans<<'\n';
	}
}

