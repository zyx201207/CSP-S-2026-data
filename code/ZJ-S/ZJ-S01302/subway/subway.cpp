#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,c,m,d,Q,i,w[500100],k[500100],j,a[1010][1010],t[1010][1010],s[1010][1010];
vector<int>p[500100];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j],p[a[i][j]].push_back(i),s[a[i][j]][i]=t[i][j];
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		int dis[500100];
		queue<int>q;
		memset(dis,127,sizeof(dis));
		dis[x]=w[x];
		q.push(x);
		while(!q.empty()){
			int fx=q.front();
			q.pop();
			for(i=0;i<p[fx].size();i++){
				for(j=1;j<=k[p[fx][i]];j++){
					int sx=a[p[fx][i]][j];
					int sb=s[fx][p[fx][i]]+s[sx][p[fx][i]];
					if(dis[sx]>dis[fx]+sb){
						dis[sx]=dis[fx]+sb;
						q.push(sx);
					}
				}
			}
		}
		cout<<dis[y]+w[y]<<"\n";
	}
	return 0;
}

