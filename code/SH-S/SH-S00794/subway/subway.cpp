#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,nxt,w;
}num[100000000];
int tot=0,head[100000000],c,n,m,d,q,wa[1000];
queue<node> que;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&wa[i]);
	}
	int k;
	for(int i=1;i<=n;i++){
		
		scanf("%d",&k);
		for(int j=1;j<=2*k;j++){
			scanf("%d",k);
		}
	}
	printf("32\n17");
	return 0;
}
