#include<iostream>
using namespace std;

typedef long long ll;
const int N=5e5+5;
int c,n,m,d,q;
ll w[N],a[N],b[N],cnt;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
		cnt+=w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d%d",&a[i],&b[i]);
			cnt+=b[i];
		}
	}
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%lld\n",cnt);
	}
	return 0;
}