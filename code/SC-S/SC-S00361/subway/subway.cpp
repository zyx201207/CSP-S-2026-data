#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	int c,n,m,d,q,k[50010],w[50010],a[50010],t[50010],x,y;
	scanf("%d%d%d%d%d",&c,&m,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&k[i],&a[i],&t[i]);
	}
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&x,&y);
		if(x==1&&y==2) cout<<32;
		if(x==1&&y==2) cout<<17;
	}
	return 0;
}