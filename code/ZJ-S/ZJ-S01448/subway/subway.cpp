#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,i,w[500010],k[1000],u[500010],v[500010],j,vis[500010],dis[1010][1010],
fx,sx,t1,t2,x,y,f[500010][5],tot,ans,jj,g[500010],e[500010][22],ee[500010][22],kk,
qd,zd;
struct node{
	int x,w;
	friend bool operator <(node q,node h){
		return q.w>h.w;
	}
}tmp;
vector <int> a[500010],b[500010];
priority_queue <node> que;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==20||c==21){
		for(i=1;i<=m;i++) cin>>w[i];
		for(i=1;i<=n;i++){
			cin>>k[i];
			for(j=1;j<=k[i];j++)
				cin>>x>>y,f[x][i]=y;
		}
		tot=1e18;
		for(i=1;i<=m;i++)
			if(f[i][1]!=0&&f[i][2]!=0){
				if(f[i][1]+f[i][2]<tot) tot=f[i][1]+f[i][2];
			}
		while(q--){
			cin>>x>>y;ans=1e18;
			if(f[x][1]!=0&&f[y][1]!=0) ans=min(ans,w[x]+w[y]+f[x][1]+f[y][1]);
			if(f[x][2]!=0&&f[y][2]!=0) ans=min(ans,w[x]+w[y]+f[x][2]+f[y][2]);
			if(f[x][1]!=0&&f[y][2]!=0) ans=min(ans,w[x]+w[y]+f[x][1]+f[y][2]+tot);
			if(f[x][2]!=0&&f[y][1]!=0) ans=min(ans,w[x]+w[y]+f[x][2]+f[y][1]+tot);
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(12<=c&&c<=19||c>=22){
		for(i=1;i<=m;i++) cin>>w[i];
		for(i=1;i<=n;i++){
			cin>>k[i];
			for(j=1;j<=k[i];j++){
				cin>>x>>y;
				g[x]++;e[x][g[x]]=i;ee[x][g[x]]=y;
			}
		}
		for(i=1;i<=500;i++)
			for(j=1;j<=500;j++) f[i][j]=1e18;
		for(i=1;i<=m;i++){
			for(j=1;j<=g[i];j++)
				for(kk=j+1;kk<=g[i];kk++)
					//u e[i][g[j]] v e[i][g[k]] w ee[i][g[j]]+ee[i][g[k]]
					f[e[i][j]][e[i][kk]]=min(f[e[i][j]][e[i][kk]],ee[i][j]+ee[i][kk]);
		}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(f[i][j]==1e18) continue;
				a[i].push_back(j);
				a[j].push_back(i);
				b[i].push_back(f[i][j]);
				b[j].push_back(f[i][j]);
			}
		while(q--){
			cin>>x>>y;ans=1e18;
			for(i=1;i<=g[x];i++)
				for(jj=1;jj<=g[y];jj++){
					qd=e[x][i];zd=e[y][jj];
					for(j=1;j<=n;j++) dis[qd][j]=1e18,vis[j]=0;
					dis[qd][qd]=0;tmp.x=qd;tmp.w=0;que.push(tmp);
					while(!que.empty()){
						fx=que.top().x;que.pop();
						if(vis[fx]==1) continue;vis[fx]=1;
						for(j=0;j<a[fx].size();j++){
							sx=a[fx][j];
							if(dis[qd][sx]>dis[qd][fx]+b[fx][j]){
								dis[qd][sx]=dis[qd][fx]+b[fx][j];
								tmp.x=sx;tmp.w=dis[qd][sx];que.push(tmp);
							}
						}
					}	
					ans=min(ans,dis[qd][zd]);
				}
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(i=1;i<=m;i++) cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k[i];
		for(j=1;j<=k[i];j++) cin>>u[j]>>v[j];
		for(t1=1;t1<=k[i];t1++)
			for(t2=t1+1;t2<=k[i];t2++){
				a[u[t1]].push_back(u[t2]);
				a[u[t2]].push_back(u[t1]);
				b[u[t1]].push_back(v[t1]+v[t2]);
				b[u[t2]].push_back(v[t1]+v[t2]);
			}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++) dis[i][j]=1e18,vis[j]=0;
		dis[i][i]=0;tmp.x=i;tmp.w=0;que.push(tmp);
		while(!que.empty()){
			fx=que.top().x;que.pop();
			if(vis[fx]==1) continue;vis[fx]=1;
			for(j=0;j<a[fx].size();j++){
				sx=a[fx][j];
				if(dis[i][sx]>dis[i][fx]+b[fx][j]){
					dis[i][sx]=dis[i][fx]+b[fx][j];
					tmp.x=sx;tmp.w=dis[i][sx];que.push(tmp);
				}
			}
		}
	}
	while(q--){
		cin>>x>>y;cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
}