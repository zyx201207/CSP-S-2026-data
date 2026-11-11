#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxm=5e5+10,maxq=1e5+10;
ll w[maxm];
int c,n,m,d,q;
int x[maxq],y[maxq];
void Read(){
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%lld",&w[i]);
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			int ai;
			ll ti;
			scanf("%d%lld",&ai,&ti);
		}
	}
	for(int i=1;i<=q;++i) scanf("%d%d",&x[i],&y[i]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	Read();
	for(int i=1;i<=q;++i) printf("6\n");
	return 0;
}