#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500010],k[510],dist[500010],dian[500010];
bool vis[500010],huan[500010];
vector<int>a[510],t[510];
map<int,int>mp[510];
struct node{
	int now,xx,yy,step;//第xx条线路的第yy个站点为now 
	bool operator <(node aa)const{
		return step>aa.step;
	}
};
void bfs(int st,int ssx,int ssy,int en){
	for(int i=1;i<=m;i++)dist[i]=INT_MAX,vis[i]=0;
	priority_queue<node>q;
	q.push({st,ssx,ssy,0});
	dist[st]=0;
	while(!q.empty()){
		node now=q.top();
		q.pop();
		if(vis[now.now])continue;
		vis[now.now]=1;
		if(huan[now.now]==1){
			for(int i=1;i<=n;i++){
				if(mp[i][now.now]!=0&&i!=now.xx){
					int lnx=i,lny=mp[i][now.now];
					int nx=i,ny=mp[i][now.now];
					if(ny-1>=1){
						ny--;
						if(now.step+t[now.xx][mp[now.xx][now.yy]]+t[lnx][lny]<dist[a[nx][ny]]){
							dist[a[nx][ny]]=now.step+t[now.xx][mp[now.xx][now.yy]]+t[lnx][lny];
							q.push({a[nx][ny],nx,ny,dist[a[nx][ny]]});
						}
						ny++;
					}
					if(ny+1<=k[nx]){
						ny++;
						if(now.step+t[now.xx][mp[now.xx][now.yy]]+t[lnx][lny]<dist[a[nx][ny]]){
							dist[a[nx][ny]]=now.step+t[now.xx][mp[now.xx][now.yy]]+t[lnx][lny];
							q.push({a[nx][ny],nx,ny,dist[a[nx][ny]]});
						}
						ny--;
					}
				}
			}
		}
		int nx=now.xx,ny=now.yy;
		if(ny-1>=1){
			ny--;
			if(now.step<dist[a[nx][ny]]){
				dist[a[nx][ny]]=now.step;
				q.push({a[nx][ny],nx,ny,now.step});
			}
			ny++;
		}
		if(ny+1<=k[nx]){
			ny++;
			if(now.step<dist[a[nx][ny]]){
				dist[a[nx][ny]]=now.step;
				q.push({a[nx][ny],nx,ny,now.step});
			}
			ny--;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+10);
		t[i].resize(k[i]+10);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			mp[i][a[i][j]]=j;
			dian[a[i][j]]++;
			if(dian[a[i][j]]>1){
				huan[a[i][j]]=1;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ss,ee;
		for(int i=1;i<=n;i++){
			if(mp[i][x]!=0){
				ss=i,ee=mp[i][x];
				break;
			}
		}
		bfs(x,ss,ee,y);
		int ss1,ee1;
		for(int i=1;i<=n;i++){
			if(mp[i][y]!=0){
				ss1=i,ee1=mp[i][y];
				break;
			}
		}
		cout<<dist[y]+w[x]+w[y]+t[ss][ee]+t[ss1][ee1]<<"\n";
	}
	return 0;
}
