#include<bits/stdc++.h>
#define gc getchar
#define fst first
#define scd second
using namespace std;
typedef long long ll;
typedef __int128 lll;
bool __(char ch){return ch>='0'&&ch<='9';}
template<typename T> inline void read(T &x){
	x=0;char ch=gc();bool sgn=0;
	while(!__(ch)&&ch!=EOF)sgn|=(ch=='-'),ch=gc();
	while(__(ch))x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	if(sgn)x=-x;
}
template<typename T,typename ...I> inline void read(T &x,I &...x1){
	read(x);
	read(x1...);
}
#define mp make_pair
const int N=5e5+5;
const int M=505;
ll c,n,m,d,q,w[N];
vector<pair<ll,ll> >vec[N];
ll f[M][M];
void add(int u,int v,ll w){
	f[u][v]=min(f[u][v],w);
	f[v][u]=min(f[v][u],w);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	read(c,n,m,d,q);
	for(int i=1;i<=m;i++)read(w[i]);
	for(int i=1;i<=n;i++){
		int k;read(k);
		for(int j=1;j<=k;j++){
			int x,y;read(x,y);
			vec[x].push_back(mp(i,y));
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++){
		for(auto t:vec[i]){
			for(auto t1:vec[i]){
				add(t.fst,t1.fst,t.scd+t1.scd);
			}
		}
	}
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;read(x,y);
		ll ans=9e18;
		for(auto t:vec[x]){
			for(auto t1:vec[y]){
				ans=min(ans,w[x]+w[y]+f[t.fst][t1.fst]+t.scd+t1.scd);
			}
		} 
		printf("%lld\n",ans);
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
