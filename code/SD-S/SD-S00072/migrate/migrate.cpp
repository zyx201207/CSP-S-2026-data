#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
//#define ull unsigned long long
using namespace std;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+(ch&15);
		ch=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int N=2e4+5;
int c,t,n,d,x[N];
vector<int>g[N];bool vis[N];int dis[N];int ji[N];
void dij(int s){
	for(int i=1;i<=n;i++) dis[i]=2e18;
//	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	priority_queue<pii> q;
	dis[s]=0,q.push({s,0});
	while(!q.empty()){
		pii tp=q.top();
		q.pop();
		if(vis[tp.first]) continue;
		vis[tp.first]=true;
		for(int v:g[tp.first]){
			if(dis[v]>dis[tp.first]+1){
				dis[v]=dis[tp.first]+1;ji[v]=0;
				q.push({v,dis[v]});
			}
			if(dis[v]==dis[tp.first]+1) ji[v]=ji[tp.first]+1;
//			else ji[v]=0;
		}
	}
}
inline int absl(int zr){
	if(zr<0) zr=-zr;
	return zr;
}//bool fl[N][N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
//		memset(fl,false,sizeof(fl));
		
		n=read(),d=read();
		for(int i=1;i<=n;i++) x[i]=read();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((int)absl(x[i]-x[j])<=d){//max(x[i],x[j])-min(x[i],x[j])
					g[j].push_back(i),g[i].push_back(j);
					//cout<<i<<" "<<j<<"\n";
				}
			}
		}int ans=0;//cout<<"fhy";
		for(int i=1;i<=n;i++){
			
			dij(i);
			for(int j=i;j<=n;j++){
//				if(fl[i][j]||fl[j][i]) continue;
				if(i==j) continue;
				if(ji[j]==2){
					ans++;//fl[i][j]=true;fl[j][i]=true;
					//cout<<i<<" "<<j<<"\n";
				}
			}
		}
		
		cout<<ans<<"\n";
		memset(ji,0,sizeof(ji));
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5

*/
