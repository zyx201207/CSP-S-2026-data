#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7,M=1010,P=510;
struct node{
	int v,id,pos;ll val;
};
int c,n,m,d,q,len[P];
ll w[N];
map<pair<int,int>,ll> ans[N];
vector<int> p[P];
vector<node> G[N];
vector<ll> val[P];
queue<node> Q;
inline void bfs(int st){
	while(!Q.empty())Q.pop();
	for(node &i:G[st]){
		ans[st][{i.v,i.pos}]=i.val;Q.push({i.v,i.id,i.pos,i.val});
	}
	int u,pos;ll cost;
	while(!Q.empty()){
		u=Q.front().v,pos=Q.front().pos,cost=Q.front().val,Q.pop();
		for(node &i:G[u]){
			if(i.v==u)continue;
			if(i.pos!=pos){
				if(ans[st].count({i.v,i.pos})==0 || ans[st][{i.v,i.pos}]>ans[st][{u,pos}]+cost+i.val){
					ans[st][{i.v,i.pos}]=ans[st][{u,pos}]+cost+i.val;
					Q.push({i.v,i.id,i.pos,val[i.pos][i.id]});
				}
			}else{
				if(ans[st].count({i.v,i.pos})==0 || ans[st][{i.v,i.pos}]>ans[st][{u,pos}]){
					ans[st][{i.v,i.pos}]=ans[st][{u,pos}];
					Q.push({i.v,i.id,i.pos,val[i.pos][i.id]});
				}
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	int u,sum=0;
	for(int i=1;i<=n;i++){
		cin>>len[i];ll v;sum+=len[i];
		for(int j=0;j<len[i];j++){
			cin>>u,p[i].push_back(u),cin>>v,val[i].push_back(v);
			if(j!=0)G[u].push_back({p[i][j-1],j-1,i,v});
		}
		for(int j=0;j<len[i]-1;j++) G[p[i][j]].push_back({p[i][j+1],j+1,i,val[i][j]});
	}
//		for(int i=1;i<=m;i++){
//			cout<<i<<": \n";
//			for(node &j:G[i]){
//				cout<<j.v<<" "<<j.pos<<" "<<j.val<<'\n';
//			}cout<<'\n';
//		}
	for(int i=1;i<=m;i++){
		bfs(i);
	}
//		for(int i=1;i<=m;i++){
//			cout<<i<<": \n";
//			for(auto j:ans[i]){
//				cout<<j.first.first<<" "<<j.first.second<<" "<<j.second<<'\n';
//			}
//		}
	int l,r;
	while(q--){
		cin>>l>>r;sum=1e18;
		for(node &i:G[r]){
			sum=min(sum,ans[l][{r,i.pos}]+i.val);
		}cout<<sum+w[l]+w[r]<<'\n';
	}
	return 0;
}