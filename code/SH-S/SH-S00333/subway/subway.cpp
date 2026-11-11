#include<bits/stdc++.h> 
using namespace std;
struct Edge{
	int to,time;
}edge[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int a[505];
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	int w[m+5];
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	int k,k1,t;
	scanf("%d%d",&k,&k1);
	for(int i=2;i<=k;i++){
		scanf("%d%d",&k1,&t);
		a[k1]=min(a[k1],t);
	}
	
	int x,y; 
	while(q--){
		scanf("%d%d",&x,&y);
		printf("%d\n",w[x]+a[x]+w[y]+a[y]);
	}
	
	return 0;
}
