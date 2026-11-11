#include<bits/stdc++.h>
#define int long long
using namespace std;
char buf[1<<20];
char *p1=buf,*p2=buf;
char gc(){
	if(p1==p2){
		p2=(p1=buf)+fread(buf,1,1<<20,stdin);
		if(p1==p2)return EOF;
	}
	return *p1++;
}
int read(){
	char c=gc();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=gc();
	}
	int x=0;
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=gc();
	}
	return x*f;
}
int c,n,m,d,q;
int w[500005];
int k[505];
map<pair<int,int>,int>ma;
vector<pair<int,int> >s[500005];
vector<pair<int,int> >g[505];
int dis[505];
int ju[505][505];
struct note{
	int x,y;
	bool operator <(const note &b)const{
		return b.y<y;
	}
};
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	priority_queue<note>q;
	q.push({s,0});
	while(!q.empty()){
		int x=q.top().x,y=q.top().y;
		q.pop();
		for(int i=0;i<g[x].size();i++){
			int yy=g[x][i].first;
			if(dis[x]+g[x][i].second<dis[yy]){
				dis[yy]=dis[x]+g[x][i].second;
				q.push({yy,dis[yy]});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();;
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int x,y; 
			x=read();
			y=read();
			ma[{i,x}]=y;
			for(int k=0;k<s[x].size();k++){
				g[i].push_back({s[x][k].first,s[x][k].second+y});
				g[s[x][k].first].push_back({i,s[x][k].second+y});
			}
			s[x].push_back({i,y});
		}
	}
	memset(ju,0x3f,sizeof(ju));
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++){
			if(i==j){
				ju[i][j]=0;
				continue;
			}
			ju[i][j]=min(ju[i][j],dis[j]);
			ju[j][i]=min(ju[j][i],dis[j]);
		}
	}
	while(q--){
		int x,y;
		x=read();
		y=read();
		int ans=w[x]+w[y];
		//cout<<x<<endl;
		int res=LONG_LONG_MAX,minn,minn1;
		for(int i=0;i<s[x].size();i++){
			for(int j=0;j<s[y].size();j++){
				if(res>ju[s[x][i].first][s[y][j].first]){
					minn=s[x][i].first;
					minn1=s[y][j].first;
					res=ju[s[x][i].first][s[y][j].first];
				}
			}
		}
		cout<<ans+res+ma[{minn,x}]+ma[{minn1,y}]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
