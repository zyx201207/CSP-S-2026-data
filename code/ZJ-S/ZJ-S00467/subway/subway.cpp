#include <bits/stdc++.h>
#define int long long
using namespace std;
int d[510],mi,chan[510][510],c,n,m,dd,qq,qd,zd,tim[500010],k[510],x,y,ans;
vector<int>f[500010],g[500010],b[510];
queue<pair<int,int> >q;
void bfs(int qd,int zd){
	int fx,fline,line;
	memset(d,127,sizeof(d));
	for(int j=0;j<f[qd].size();j++){
		for(int i=0;i<b[f[qd][j]].size();i++)
		 	q.push(make_pair(b[f[qd][j]][i],f[qd][j]));
		d[f[qd][j]]=g[qd][j];		
	}

	while(!q.empty()){
		fx=q.front().first;fline=q.front().second;q.pop();
		for(int i=0;i<f[zd].size();i++)
			if(f[zd][i]==fline) mi=min(mi,d[fline]+g[zd][i]);
		for(int i=0;i<f[fx].size();i++){
			line=f[fx][i];
			if(line!=fline){
				if(d[line]<=d[fline]+chan[fline][line]) continue;
				d[line]=d[fline]+chan[fline][line];
				for(int j=0;j<b[line].size();j++)
					q.push(make_pair(b[line][j],line));						
			}
		
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>dd>>qq;
	for(int i=1;i<=m;i++) cin>>tim[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			f[x].push_back(i);
			g[x].push_back(y);
		}
	}
	for(int i=1;i<=m;i++)
		if(f[i].size()>1){
			x=f[i].size();
			for(int j=0;j<x;j++){
				for(int k=j+1;k<x;k++)
					chan[f[i][j]][f[i][k]]=chan[f[i][k]][f[i][j]]=g[i][j]+g[i][k];
				b[f[i][j]].push_back(i);				
			}

		}
	while(qq--){
		cin>>qd>>zd;
		ans=tim[qd]+tim[zd];
		mi=1e18;
		bfs(qd,zd);
		cout<<ans+mi<<"\n";
	}
	return 0;
}