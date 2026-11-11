#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll c,n,m,x,y,d,q,k,w[N],lx,ly,t;
struct node{
	int x,len;
}a[N];
//void add(int x,int y){
//	if(pre[u]==0){
//		a[++k]={v,m[x]+m[y],pre[u]};
//		pre[u]=k;
//	}
//	else{
//		
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&t);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a[i].x,&a[i].len);
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",x);
	}
	return 0;
}
