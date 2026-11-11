#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int MAXN=5e5+5;
const int MAXM=505;
const ll INF=1e18;
int c,n,m,d,q,w[MAXN];
ll f[MAXM][MAXM];
vector<pair<int,ll> > l[MAXN];
int read(){
	int x=0,f=1,c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void init(){
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) f[i][i]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	init();
	for(int i=1;i<=n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int a=read(),t=read();
			int len=l[a].size();
			for(int v=0;v<len;v++){
				f[l[a][v].first][i]=min(f[l[a][v].first][i],1ll*t+l[a][v].second);
				f[i][l[a][v].first]=min(f[i][l[a][v].first],1ll*t+l[a][v].second);
			}
			l[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		ll ans=INF;
		int x=read(),y=read();
		int len1=l[x].size();
		int len2=l[y].size();
		for(int i=0;i<len1;i++){
			for(int j=0;j<len2;j++){
				ans=min(ans,f[l[x][i].first][l[y][j].first]+w[x]+w[y]+l[x][i].second+l[y][j].second);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}





