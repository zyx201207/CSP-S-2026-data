#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)

const int maxm = 5e5+6;
const int maxn = 5e2+6;

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

ll c,n,m,d,q,k,u,v,ans,w[maxm],dis[maxn][maxn];
bool has_node[maxn][maxm];
vector<ll>a[maxn],t[maxn];
vector<pair<ll,ll> >line[maxm];

inline void Floyd(){
	rep(k,1,n)
	    rep(i,1,n) rep(j,1,n)
	        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	return;
}

inline void solve(){
	ans=1e18;
	u=read(),v=read();
	for(int i=0;i<line[u].size();++i)
		for(int j=0;j<line[v].size();++j){
			//cout<<"dis["<<line[u][i].first<<"]["<<line[v][j].first<<"]: "<<dis[line[u][i].first][line[v][j].first]<<'\n';
			ans=min(ans,dis[line[u][i].first][line[v][j].first]+w[u]+w[v]+t[line[u][i].first][line[u][i].second]+t[line[v][j].first][line[v][j].second]);
    }
    write(ans),putchar('\n');
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
    c=read(),n=read(),m=read(),d=read(),q=read();
    rep(i,1,m) w[i]=read();
    rep(i,1,n){
    	k=read();
        rep(j,0,k-1){
        	u=read(),v=read();
        	has_node[i][u]=true;
        	a[i].emplace_back(u),t[i].emplace_back(v);
        	line[u].emplace_back(make_pair(i,j)); //bingo
		}
	}
	/*rep(p,1,m){
		cout<<p<<": "<<'\n';
	    for(auto it:line[p])
	        cout<<it.first<<' '<<it.second<<'\n';
	}*/
	rep(p,1,m) //p是点 line[x][y].first是线路 
		for(int i=0;i<line[p].size();++i)
		    for(int j=i+1;j<line[p].size();++j){
		    	dis[line[p][i].first][line[p][j].first]=dis[line[p][j].first][line[p][i].first]=min(dis[line[p][i].first][line[p][j].first],t[line[p][i].first][line[p][i].second]+t[line[p][j].first][line[p][j].second]);
			}
	rep(i,1,n) dis[i][i]=0;
	/*rep(i,1,n){
		rep(j,1,n) cout<<dis[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';*/
	Floyd();
	/*rep(i,1,n){
		rep(j,1,n) cout<<dis[i][j]<<' ';
		cout<<'\n';
	}*/
	while(q--) solve();
	return 0;
}


/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
