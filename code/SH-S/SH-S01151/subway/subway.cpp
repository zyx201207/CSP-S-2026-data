#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=109;
const int M=100009;

int c,n,m,d,q,x,y,k[M],cnt;
ll w[N],t[M][N],a[M][N],ans=0;
vector<int> to[N];
void bfs(){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<to[u].size();i++){
			int v=to[u][i];
			q.push(v);
			cnt++;
			if(v==y)	continue;
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	ll res=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			res=t[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k[i];j++){
			to[a[i][j-1]].push_back(a[i][j]);
		}
	}
	while(q--){
		cin>>x>>y;
		bfs();
		cout<<cnt*res+w[x]+w[y]<<'\n';
	}
	return 0;
}
