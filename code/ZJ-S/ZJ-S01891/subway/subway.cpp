#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int MAXN=5e2+10,MAXM=2e4+10;
int T=1;
int c,n,m,d,Q;
int w[MAXM];
int k;
vector<int>belong[MAXM],exc[MAXM];
int rode[MAXN][MAXN];
//Á´Ê½Ç°ÏòÐÇ
struct EDGE{int from,to,w,rode,nxt;}edge[MAXM];
int head[MAXN],TOT=1;
void add(int u,int v,int w){
	edge[TOT].from=u;edge[TOT].to=v;edge[TOT].w=w;
	edge[TOT].nxt=head[u];head[u]=TOT++;
} 
void solve(){
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1,a,t;j<=k;++j){
			cin>>a>>t;
			belong[a].push_back(i);
			exc[a].push_back(t);
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) rode[i][j]=4e18;
	for(int i=1;i<=n;++i) rode[i][i]=0;
	for(int i=1;i<=m;++i){
		int siz=belong[i].size();
		for(int j=0;j<siz;++j){
			for(int k=j+1;k<siz;++k){
				int num=exc[i][j]+exc[i][k];
				int J=belong[i][j],K=belong[i][k];
				if(rode[J][K]>num){
					rode[J][K]=num;
					rode[K][J]=num;
				}
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				rode[i][j]=min(rode[i][j],rode[i][k]+rode[k][j]);
			}
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		int sizx=belong[x].size(),sizy=belong[y].size();
		int ans=4e18;
		for(int i=0;i<sizx;++i){
			for(int j=0;j<sizy;++j){
				int bi=belong[x][i],bj=belong[y][j];
				int ei=exc[x][i],ej=exc[y][j];
				int t=rode[bi][bj]+ei+ej+w[x]+w[y];
				ans=min(ans,t);
			}
		}
		cout<<ans<<endl;
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//cout<<fixed<<setprecision(2);
	//cin>>T;
	while(T--) solve();
	return 0;
}
