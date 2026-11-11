#include<bits/stdc++.h>
using namespace std;
int u[2000006],v[2000006];
int f[2000006];
int n,k;
int find(int x){
	if(x==f[x]) return f[x];
	else return find(f[x]);
}
void add(int x,int y){
	int g=find(x),h=find(y);
	if(g!=h){
		f[x]=y;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	for(int i=1;i<=t;i++){
		scanf("%d %d",&n,&k);
		for(int j=1;j<=n;j++){
			f[j]=j;
		}
		for(int j=1;j<=n-1;j++){
			scanf("%d %d",&u[j],&v[j]);
			add(u[j],v[j]);
		}
		printf("%d\n",abs(u[n-1]-v[n-1]));
	}
	return 0;
}
