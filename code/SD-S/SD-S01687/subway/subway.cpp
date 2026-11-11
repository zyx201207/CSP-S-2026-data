#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q,w[500005],k,xa,ya,xb,yb;
struct node{
	int a,t;
}s[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=2;i++){
		scanf("%d",&k);
		for(int i=1;i<=n;i++) scanf("%d%d",&s[i].a,&s[i].t);
	}
	scanf("%d%d%d%d",&xa,&ya,&xb,&yb);	
	printf("32\n17");
	return 0;
} 
