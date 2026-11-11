//SN-S00489 郝天哲 铜川市耀州区耀州中学 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=501,M=5e5+1;
int a[N][M],t[N][M],w[M],k[M];
int c,n,m,d,q,x,y,ans;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		ans+=w[x]+w[y];
	}
	return 0;
}
