#include <bits/stdc++.h>
#define int long long
using namespace std;
int x,y,n,m,d,T,l,r,i,j,k,fx,fb,sx,sb,w[500010],dis[500010];
vector<int> f[500010],g[500010];
queue<int> q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>x>>n>>m>>d>>T;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k;m++;
		for(j=1;j<=k;j++){
			cin>>x>>y;
			f[m].push_back(x);
			f[x].push_back(m);
			g[m].push_back(y);
			g[x].push_back(y);
		}
	}
	while(T--){
		cin>>l>>r;
		memset(dis,127,sizeof(dis));
		q.push(l);dis[l]=0;
		while(!q.empty()){
			fx=q.front();
			fb=dis[fx];
			q.pop();
			for(i=0;i<f[fx].size();i++){
				sx=f[fx][i];
				sb=fb+g[fx][i];
				if(sb<dis[sx]){
					dis[sx]=sb;
					q.push(sx);
				}
			}
		}
		cout<<dis[r]+w[l]+w[r]<<"\n";
	}
}
