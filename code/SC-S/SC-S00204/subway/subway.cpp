#include<bits/stdc++.h>
using namespace std;
long long s,c,n,m,d,q,k[20005],a[505][20005],t[505][50005],w[20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%ld%ld%ld%ld%ld",&c,&n,&m,&d,&q);
	s=0;
	for(long long i=1;i<=m;i++) scanf("%ld",&w[i]); 
	for(long long i=1;i<=n;i++){
		scanf("%ld",&k[i]);
		for(long long j=1;j<=k[i];j++) {
			scanf("%ld%ld",&a[i][j],&t[i][j]);
			s+=t[i][j];
		}
	}
	while(q--){
		long long st,en;
		scanf("%ld%ld",&st,&en);
		printf("%ld\n",s);
	}
	return 0;
}