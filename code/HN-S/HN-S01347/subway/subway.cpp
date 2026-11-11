#include<bits/stdc++.h>
#define P pair<long long,long long>
using namespace std;
const int maxm=5e5+5,maxn=5e2+2;
long long c,n,m,d,q,w[maxm],k,a[maxm],t[maxm],x,y,dl[maxn][maxn];
bool b[maxn],e[maxn];
vector <P> g[maxn];
void dij(){
	for(int i=1;i<=n;i++){
		dl[x][i]=0x3f3f3f3f;
	}	
	priority_queue< P , vector <P>, greater<P> > que;
	que.push(P(0,x));
	dl[x][x]=0;
	while(!que.empty()){
		P p=que.top();que.pop();
		int j=p.second;
		if(b[j]){
			continue;
		}
		b[j]=true;
		for(unsigned long long i=0;i<g[j].size();i++){
			que.push(P(g[j][i].first+p.first,g[j][i].second));
		}
		dl[x][j]=p.first;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[j],&t[j]);
			for(int k=1;k<j;k++){
				g[a[j]].push_back(P(t[j]+t[k],a[k]));
				g[a[k]].push_back(P(t[j]+t[k],a[j]));
			}
		}
	}
	while(q--){
		memset(b,0,sizeof(b));
		scanf("%lld%lld",&x,&y);
		if(!e[x]){
			e[x]=true;
			dij();
		}
		long long ans=w[x]+dl[x][y]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
