#include<bits/stdc++.h>
#define p pair<int,int>
using namespace std;
int c,n,m,d,qq;
int ww[5100],k[505],dis[10005],vis[5005],t[5005][5005];
int uu[5005][5005],kk[5005];
vector<int> v[5005];
vector<int> w[5005];
priority_queue<p,vector<p>,greater<p> >q;
void subb(int xx,int yy){
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[xx]=0;
	q.push({0,xx});
	while(q.size()){
		p tmp=q.top();
		q.pop();
		int x=tmp.second;
		for(int i=0;i<v[x].size();i++){
			int y=v[x][i];
			if(dis[y]>dis[x]+w[x][i]){
				if(vis[x]!=0){
					if(t[vis[x]][x]!=t[x][y]){
						dis[y]=uu[t[vis[x]][x]][x]+uu[t[x][x]][x];
						vis[x]=0;
					}
				}
				if(dis[y]!=0x3f3f3f3f) dis[y]+=dis[x]+w[x][i];
				else dis[y]=dis[x]+w[x][i];
				vis[y]=x;
				q.push({dis[y],y});
			}
		}
	}
	cout<<dis[yy]+ww[xx]+ww[yy]+kk[yy]<<endl;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>ww[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		cout<<i<<endl;
		int tmp1,tmp2;
		cin>>tmp1>>tmp2; 
		for(int j=1;j<=k[i]-1;j++){
			int u,time;
			cin>>u>>time;
			v[tmp1].push_back(u);
			t[tmp1][u]=i;
			t[u][tmp1]=i;
			v[u].push_back(tmp1);
			w[tmp1].push_back(tmp2);
			w[u].push_back(time);
			uu[i][tmp1]=tmp2;
			uu[i][u]=time;
			kk[tmp1]=tmp2;
			tmp1=u;
			tmp2=time;
		}
	}
	for(int k=1;k<=qq;k++){
		int x,y;
		cin>>x>>y;
		subb(x,y);
	}
	return 0;
} 
