#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ans,a,aa,bb,t,q,c,w[500009],k,d[1009][1009],l;

void solve(){
	for(int k=0;k<=l;k++)
		for(int i=0;i<=l;i++)
			for(int j=0;j<=l;j++)
				d[j][i]=d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&c,&q);
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		while(k--){
			scanf("%lld%lld",&a,&t);
			d[i][a+n]=d[a+n][i]=t;
			l=max(a+n,l);
		}
	}
	solve();
/**	for(int i=1;i<=l;i++){
		for(int j=1;j<=l;j++)
			printf("%lld,%lld:%lld\t",i,j,d[i][j]);
		puts("");
	}*/
	while(q--){
		scanf("%lld%lld",&aa,&bb);
		printf("%lld\n",d[aa+n][bb+n]+w[aa]+w[bb]);
	}
}
