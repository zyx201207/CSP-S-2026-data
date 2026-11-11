#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=5e5+5,maxn=505;
int w[maxm];
struct node{
	int x,t;
};
struct f{
	int k;
	vector<node> a;
}e[maxn];
vector<node> vis;
void bfs(int s,int t){
	queue<f> q;
//	for(int i=0;i<vis[s].size();i++) q.push({s,})
//	while(!q.empty()){
//		int u=q.front();
//		q.pop();
//		for(int i=0;i<e[u].k;i++){
//			int x=e[u].a[i].x,t=e[u].a[i].t;
//			
//		}
//	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n/*ÏßÂ·*/,m/*µã*/,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	while(q--){
		int s,t;
		cin>>s>>t;
		cout<<w[s]+w[t]<<endl;
	}
	return 0;
	/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		e[i].k=k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			vis[x].push_back({i,t});
			e[i].a[j].push_back({x,t});
			
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		bfs(s,t);
	}
	*/
	return 0;
}

