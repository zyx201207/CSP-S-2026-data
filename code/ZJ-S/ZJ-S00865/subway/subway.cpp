#include<bits/stdc++.h>
#define int long long
#define il inline
#define put putchar
#define pb emplace_back
#define fir first
#define sec second
#define mk make_pair
using namespace std;
typedef pair<int,int> pii;
il int rd(){
	int sum=0,p=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		sum=sum*10+(ch-'0');
		ch=getchar(); 
	}
	return sum*p;
}
il void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}
const int JYAAKIOI=1e18,N=5e2+5,M=5e5+5;
int c,n,m,d,q,w[M],k[N],f[N][N];
vector<pii>g[M+N];
vector<int>a[N],t[N]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd();n=rd();m=rd();d=rd();q=rd();
	for(int i=1;i<=m;++i)w[i]=rd();
	for(int i=1;i<=n;++i){
		k[i]=rd();a[i].resize(k[i]+5);t[i].resize(k[i]+5);
		for(int j=1;j<=k[i];++j){
			a[i][j]=rd();t[i][j]=rd();
			g[i+m].pb(mk(a[i][j],t[i][j]));
			g[a[i][j]].pb(mk(i+m,t[i][j]));
		}
	}
//	for(int i=1;i<=n;++i)dij(i);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;++i){
		for(int j=0;j<g[i].size();++j){
			for(int k=0;k<g[i].size();++k){
				if(j==k)continue;
				int u=g[i][j].fir,v=g[i][k].fir;
				f[u-m][v-m]=min(f[u-m][v-m],g[i][j].sec+g[i][k].sec);
			}
		}
	}
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	while(q--){
		int x=rd(),y=rd();
		int ans=JYAAKIOI;
		for(auto u:g[x]){
			for(auto v:g[y]){
				//ans=min(ans,dis[u.fir-m][v.fir-m]+u.sec+v.sec);
				ans=min(ans,f[u.fir-m][v.fir-m]+u.sec+v.sec);
			}
		}
		wr(ans+w[x]+w[y]),put('\n');
	}
	return 0;
}