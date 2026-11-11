#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,z;
int w[500005],vis[500005];
struct node {
	int t,x,j;
};
vector<node>vc[500005];
int ve[505][500005];
void bfs(int sx,int sy) {
	queue<int>q;
	q.push(sx);
	vis[sx]=w[sx];
	int rj=0;
	while(q.size()) {
		int r=q.front();
		q.pop();
		for(auto y:vc[r]) {
			if(!vis[y.x]) {
				q.push(y.x);
				if(y.j!=rj) {
					vis[r]+=ve[r][y.j];
					vis[r]+=ve[r][rj];
					rj=y.j;
				}
				vis[y.x]=vis[r];
			}
	    }
	    if(vis[sy])break;
	}
	vis[sy]+=ve[sy][rj]+w[sy];
}
bool cmp(node a,node b)
{
	if(a.t>b.t)return a.t<b.t;
	else a.x<b.x;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int l=1; l<=k; l++) {
			int a,t;
			cin>>a>>t;
			vc[a].push_back({t,z,i});
			vc[z].push_back({t,a,i});
			ve[a][i]=t;
			z=a;
		}
		for(int l=1;l<=m;l++)
		{
			sort(vc[l].begin(),vc[l].end(),cmp);
		}
	}
	while(q--) {
		int rs,rt;
		cin>>rs>>rt;
		bfs(rs,rt);
		cout<<vis[rt]<<endl;
		memset(vis,0,sizeof(vis));
	}
}