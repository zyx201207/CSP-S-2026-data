#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],k[500005];
struct node {
	int a,t;
};
vector<node>vec[500005];
int ans;
struct node2{
	int stay,ans,line;
};
int b[500005];
int c,n,m,d,q;
void bfs(int x,int en){
	queue<node2>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(vec[i][j].a==x){
				q.push({x,w[x]+vec[i][j].t,i});
			}
		}
	}
	b[x]=1;
	while(q.size()){
		node2 p=q.front();
		q.pop();
		if(p.stay==en){
			ans=max(ans,p.ans);
			continue;
		}
		for(int i=1;i<=k[p.line];i++){
			if(b[vec[p.line][i].a]==0){
				q.push({i,p.ans,p.line});
			}
		}
		for(int i=1;i<=n&&i!=p.line;i++){
			for(int j=1;j<=k[i];j++){
				if(b[vec[i][j].a]==0){
					q.push({j,p.ans+vec[p.line][j].t+vec[i][j].t,i});
				}
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			int a,t;
			cin>>a>>t;
			vec[i].push_back({a,t});
		}
	}
	int x,y;
	while(cin>>x>>y){
		ans=0;
		bfs(x,y);
		cout<<ans<<endl;
	}
	return 0;
}
