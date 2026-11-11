#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define foR(i,j,k) for(int i=(j);i>=(k);i--)
#define ull unsigned long long
#define double long double
#define i128 __int128
#define int long long
#define vi vector<int>
#define pb push_back
#define endl "\n"
using namespace std;
const int INF=1e16;
const int N=1e6+10;
int n,k,ans;
vi g[N];
pair<int,int>e[N];
int dis[N];
bool vis[N];
void init(){
	ans=INF;
	For(i,1,n){
		g[i].clear();
		dis[i]=INF;
		vis[i]=0;
	}
	return;
}
void init_bfs(){
	For(i,1,n){
		dis[i]=INF;
		vis[i]=0;
	}
	return;
}
void bfs(int st){
	For(i,1,n)vis[i]=0;
	dis[st]=0;vis[st]=1;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i:g[u]){
			if(dis[i]>dis[u]+1){
				dis[i]=dis[u]+1;
				if(vis[i])continue;
				vis[i]=1;
				q.push(i);
			}
		}
	}
	return;
}
int fa[N];
void init_bcj(){
	For(i,1,n)fa[i]=i;
	return;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void hb(int x,int y){
	x=find(x);y=find(y);
	fa[x]=y;
	return;
}
void solve(){
	cin>>n>>k;
	init();
	For(i,1,n-1){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
		e[i]={u,v};
	}
	For(S,0,(1ll<<n)-1){
		if(__builtin_popcount(S)!=k)continue;
		init_bcj();
		For(i,1,n-1){
			if(((S>>(e[i].first-1))&1)&&(S>>(e[i].second-1))&1)
				hb(e[i].first,e[i].second);
		}
		bool flag=1;
		int pa1=0,pa2=0;
		For(i,1,n){
			if((S>>(i-1))&1){
				int fai=find(i);
				if(fai==pa1||fai==pa2)continue;
				if(!pa1){
					pa1=fai;
					continue;
				}
				if(!pa2){
					pa2=fai;
					continue;
				}
				flag=0;
				break;
			}
		}
		if(!flag)continue;
		init_bfs();
		For(i,1,n){
			if((S>>(i-1))&1){
				bfs(i);
//				cerr<<i<<"--"<<endl;
//				For(j,1,n)cerr<<j<<" "<<dis[j]<<"**"<<endl;
			}
		}
		int res=0;
		For(i,1,n){
			res=max(res,dis[i]);
//			cerr<<i<<" "<<dis[i]<<"++"<<endl;
		}
		ans=min(ans,res);
//		cerr<<S<<"&&"<<res<<endl;
	}
	cout<<ans<<endl;
//	cerr<<"!!"<<endl<<endl<<endl;
	return;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1,csdbh;
	cin>>csdbh>>T;
	while(T--)solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
