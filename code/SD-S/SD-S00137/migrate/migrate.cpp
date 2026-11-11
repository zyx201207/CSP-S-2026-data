#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

const int maxn = 2e6+6;
const int smalln = 3e2+6;

inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<1ll)+(x<<3ll)+(ch^48);
	return x*f;
}

inline void write(ll x){
	if(x<0){
		putchar('-'),write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10+48);
	return;
}

struct node{
	ll id,dist;
	friend bool operator<(const node& x,const node& y){
		return x.dist>y.dist;
	}
};

ll c,n,d,ans,a[maxn],dis[smalln],cnt[smalln];
bool vis[smalln];
vector<ll>edge[smalln];

//inline void Floyd(){
//	rep(k,1,n)
//	    rep(i,1,n) rep(j,1,n){
//		    if(dis[i][j]>dis[i][k]+dis[k][j])
//		        dis[i][j]=dis[i][k]+dis[k][j],cnt[i][j]=1;
//		    else if(dis[i][j]==dis[i][k]+dis[k][j])
//		        ++cnt[i][j];
//	    }
//	return;
//}

inline void Dijkstra(ll st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	priority_queue<node>q;
	q.push((node){st,dis[st]=0}),cnt[st]=1;
	while(!q.empty()){
		auto u=q.top();
		q.pop();
		if(vis[u.id]) continue;
		vis[u.id]=true;
		for(auto v:edge[u.id]){
			if(dis[v]>dis[u.id]+1)
			    q.push((node){v,dis[v]=dis[u.id]+1}),cnt[v]=cnt[u.id];
			else if(dis[v]==dis[u.id]+1)
			    cnt[v]+=cnt[u.id];
		}
	}
	return;
}

/*
inline void Test1_6(){
	ans=0;
	rep(i,1,n) rep(j,1,n) dis[i][j]=1e18,cnt[i][j]=0;
	rep(i,1,n) dis[i][i]=1;
	rep(i,1,n) rep(j,i+1,n)
	    if(llabs(a[i]-a[j])<=d) dis[i][j]=dis[j][i]=1;
	Floyd();
	if(n==10&d==3){
		rep(i,1,n){
		    rep(j,1,n) cout<<dis[i][j]<<' ';
		    cout<<'\n';
	    }
	    cout<<'\n';
	    rep(i,1,n){
		    rep(j,1,n) cout<<cnt[i][j]<<' ';
		    cout<<'\n';
	    }
	}
	rep(i,1,n){
		rep(j,1,n) cout<<dis[i][j]<<' ';
		cout<<'\n';
	}
	rep(i,1,n){
		rep(j,1,n) cout<<cnt[i][j]<<' ';
		cout<<'\n';
	}
	rep(i,1,n) rep(j,1,n)
	    if(cnt[i][j]==2) ++ans;
	write(ans>>1ll),putchar('\n');
	return;
}*/

inline void Test1_6(){
	ans=0;
	rep(i,1,n) edge[i].clear();
	rep(i,1,n) rep(j,1,n)
	    if(llabs(a[i]-a[j])<=d)
	        edge[i].emplace_back(j)/*,edge[j].emplace_back(i)*/;
	rep(i,1,n){
		Dijkstra(i);
		rep(j,1,n){
			//cout<<cnt[j]<<' ';
			if(cnt[j]==2) ++ans;
		}
		//cout<<'\n';
    }
	write(ans>>1ll),putchar('\n');
	return;
}

inline void solve(){
	n=read(),d=read();
	rep(i,1,n) a[i]=read();
	if(c>=0&&c<=6){
		Test1_6();
		return;
	}
	return;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read();
	ll _=read();
    while(_--) solve();
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/

