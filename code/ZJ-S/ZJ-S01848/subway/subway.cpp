#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define il inline

const int N=505,M=5e5+5,mod=1e9+7;

int c,n,m,d,q;
int dis[M];
int w[M];
int k[N],x,y;
int cnt[M];
vector<int> a[N],t[N],ed[M],p[N],s[N];
vector<pair<int,int> > v;
int vis[M];

struct node{
	int x,y;
};

int bfs(int x,int y){
	for(int i=1;i<=m;i++) vis[i]=(1LL<<30);
	int minn=(1LL<<30);
	queue<node> q;
	q.push({x,0});
	while(!q.empty()){
		node K=q.front();
		int f=0,k=K.x,w,wi,wj,wj2;
		if(K.y>=minn) continue;
	//	cout<<K.x<<' '<<K.y<<'\n';
		q.pop();
		// ed[k] : sta. k's edges
		for(int i=0;i<ed[k].size();i++){
			for(int j=0;j<a[ed[k][i]].size();j++){
				if(a[ed[k][i]][j]==y){
					f=1;wi=i;wj=j;
				}else if(a[ed[k][i]][j]==k) wi=i,wj2=j;
			}
		}
		if(f){
			minn=K.y+t[ed[k][wi]][wj]+t[ed[k][wi]][wj2];
			continue;
		}
		// p[i] : edge i's sta
		for(int i=0;i<ed[k].size();i++){
			for(int j=0;j<p[ed[k][i]].size();j++){
				if(vis[p[ed[k][i]][j]]>K.y){
					int R,P,Q,F=0;
					for(int ii=0;ii<ed[k].size();ii++){
						for(int jj=0;jj<a[ed[k][ii]].size();jj++) if(a[ed[k][ii]][jj]==k){R=ed[k][ii],Q=jj;break;
						}
					}for(int ii=0;ii<ed[k].size();ii++){
						for(int jj=0;jj<a[ed[k][ii]].size();jj++) if(a[ed[k][ii]][jj]==p[ed[k][i]][j]){P=jj;break;
						}
					}
			//		cout<<R<<' '<<P<<' '<<Q<<'\n';
					vis[p[ed[k][i]][j]]=K.y,q.push({p[ed[k][i]][j],K.y+t[R][P]+t[R][Q]});
			//		cout<<t[R][P]<<' '<<t[R][Q]<<'\n';
				}
			}
		}
	}
	return minn;
}

void solve(){
	cin>>x>>y;
	int ans=w[x]+w[y];
	ans+=bfs(x,y);
	cout<<ans<<'\n';
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+5),t[i].resize(k[i]+5);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cnt[a[i][j]]++;
			ed[a[i][j]].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) if(cnt[a[i][j]]>1){
			p[i].push_back(a[i][j]);
			s[i].push_back(j);
		}
	}
	while(q--){
		solve();
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
