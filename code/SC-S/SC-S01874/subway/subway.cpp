#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
typedef pair<int,int> pii;
const int maxn=5e3+5;
vector<int>g[maxn];
int timeout[maxn];
int timek[505][maxn];
int tim[maxn][maxn];
bool vis[maxn][maxn];

void dj(int st,int stt){
	for(int i=0;i<g[st].size();++i){
		if(vis[st][g[st][i]])continue;
		vis[st][g[st][i]]=1;
		tim[stt][g[st][i]]=min(tim[stt][g[st][i]],tim[stt][st]+tim[st][g[st][i]]);
		tim[g[st][i]][stt]=tim[stt][g[st][i]];
		
		
		dj(g[st][i],stt);
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(tim,0x3f,sizeof(tim));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)scanf("%d",&timeout[i]);
	for(int i=1;i<=n;++i){
		int k;cin>>k;int tt;
		for(int j=1;j<=k;++j){
			int a[maxn];
			scanf("%d%d",&a[j],&tt);
			timek[i][a[j]]=tt;
			for(int kk=1;kk<j;++kk){
				g[a[j]].push_back(a[kk]);
				g[a[kk]].push_back(a[j]);
				tim[a[j]][a[kk]]=timek[i][a[j]]+timek[i][a[kk]];
				tim[a[kk]][a[j]]=timek[i][a[j]]+timek[i][a[kk]];
			}
		}
	}

	while(q--){
		int s,e;
		scanf("%d%d",&s,&e);
		if(tim[s][e]<0x3f3f3f3f){
			printf("%d\n",timeout[s]+timeout[e]+tim[s][e]);
			continue;
		}
		memset(vis,0,sizeof(vis));
		vis[s][s]=1;
		dj(s,s);
		printf("%d\n",timeout[s]+timeout[e]+tim[s][e]);
	}
	return 0;
}
