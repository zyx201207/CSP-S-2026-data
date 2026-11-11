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
const int N=5e5+10;
int csdbh,n,m,d,q;
int w[N];
vi line[N];
map<int,int>t[510];
int dis[510][510];
void solve(){
	cin>>csdbh>>n>>m>>d>>q;
	For(i,1,m)cin>>w[i];
	For(i,1,n){
		int k;
		cin>>k;
		while(k--){
			int a,ti;
			cin>>a>>ti;
			line[a].pb(i);
			t[i][a]=ti;
		}
		For(j,1,n)dis[i][j]=(i==j?0:INF);
	}
	For(i,1,m){
		for(int x:line[i]){
			for(int y:line[i]){
				if(x==y)continue;
				dis[x][y]=min(dis[x][y],t[x][i]+t[y][i]);
			}
		}
	}
	For(k,1,n){
		For(i,1,n){
			For(j,1,n){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		int ans=INF;
		for(int x:line[a]){
			for(int y:line[b]){
				ans=min(ans,dis[x][y]+t[x][a]+t[y][b]);
			}
		}
		cout<<ans+w[a]+w[b]<<endl;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}
