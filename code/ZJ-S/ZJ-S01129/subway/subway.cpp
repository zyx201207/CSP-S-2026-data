#include<bits/stdc++.h>
#define int long long
using namespace std;
int l,r,x,y,w[100010],c,k,n,m,d,T,vis[100010][3],dis[510][30010][3],fx,z,sx,sb,i,j;
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
vector<int> f[100010],ff[100010],e[100010],ee[100010];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>k;
		for(j=1;j<=k;j++){
			cin>>x>>y;
			f[x].push_back(i);
			ff[x].push_back(y);
			e[i].push_back(x);
			ee[i].push_back(y);
		}
	}memset(dis,127,sizeof dis);
	for(i=1;i<=max(n,m);i++){
		for(j=1;j<=max(n,m);j++)vis[j][0]=vis[j][1]=vis[j][2]=0;
		q.push({0,{0,i}});vis[i][0]=1;dis[i][i][0]=0;
		while(!q.empty()){
			fx=q.top().second.second;z=q.top().second.first;q.pop();
			if(z==0){
				if(dis[i][fx][0]+w[fx]>=dis[i][fx][1])continue;
				vis[fx][1]=1;dis[i][fx][1]=dis[i][fx][0]+w[fx];
				q.push({dis[i][fx][1],{1,fx}});
			}
			else if(z==1){
				for(j=0;j<f[fx].size();j++){
					sx=f[fx][j];sb=ff[fx][j];
					if(dis[i][fx][1]+sb>=dis[i][sx][2])continue;
					vis[sx][2]=1;dis[i][sx][2]=dis[i][fx][1]+sb;
					q.push({dis[i][sx][2],{2,sx}});
				}
				if(dis[i][fx][1]+w[fx]>=dis[i][fx][0])continue;
				dis[i][fx][0]=dis[i][fx][1]+w[fx];
				q.push({dis[i][fx][0],{0,fx}});
			}
			else if(z==2){
				for(j=0;j<e[fx].size();j++){
					sx=e[fx][j];sb=ee[fx][j];
					if(dis[i][fx][2]+sb>=dis[i][sx][1])continue;
					vis[sx][1]=1;dis[i][sx][1]=dis[i][fx][2]+sb;
					q.push({dis[i][sx][1],{1,sx}});
				}
			}
		}
	}
	while(T--){
		cin>>l>>r;
		cout<<dis[l][r][0]<<"\n";
	}
	return 0;
}

