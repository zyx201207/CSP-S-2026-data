#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001];
vector<pair<int,int> >v[500001];
int k[501];
long long dis[501][501];
int read(){
	char w;
	while(w=getchar(),w<'0'||w>'9');
	int x=w-'0';
	while(w=getchar(),w>='0'&&w<='9')x*=10,x+=w-'0';
	return x;
}
void print(long long gg){
	string str=to_string(gg);
	for(int i=0;i<str.size();++i)putchar(str[i]);
	putchar('\n');
}
int a,t,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		k[i]=read();
		for(int j=1;j<=k[i];++j){
			a=read(),t=read();
			v[a].push_back(make_pair(i,t));
		}
	}
	memset(dis,0x3f3f3f3f3f3f3f,sizeof(dis));
	for(int a=1;a<=m;++a){
		for(int i=0;i<v[a].size()-1;++i){
			for(int j=i+1;j<v[a].size();++j){
				dis[v[a][i].first][v[a][j].first]=dis[v[a][j].first][v[a][i].first]=v[a][j].second+v[a][i].second;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=j;k<=n;++k){
				if(k==j)dis[k][j]=dis[j][k]=0;
				dis[k][j]=dis[j][k]=min(dis[j][k],dis[i][j]+dis[i][k]);
			}
		}
	}
	for(int i=1;i<=q;++i){
		x=read(),y=read();
		long long minn=0x3f3f3f3f3f3f3f;
		for(int i=0;i<v[x].size();++i){
			for(int j=0;j<v[y].size();++j){
				minn=min(minn,dis[v[x][i].first][v[y][j].first]+v[x][i].second+v[y][j].second);
			}
		}
		print(minn+w[x]+w[y]);
	}
}
