#include<bits/stdc++.h>
using namespace std;
const int N=1000+5;
int c,n,m,d,q,w[N],k[N],a[N][N],t,x,y,mi;
struct dt{
	int vis=0;
	int t[N],a[N];
	int cnt=0;
}A[N];
void DBfs(int x,int ans,int xi){
	A[x].vis=1;
	if(x==y){
		mi=min(mi,ans);
	}
	for(int i=1;i<=A[x].cnt;i++){
		for(int j=1;j<=k[A[x].a[i]];j++){
			if(A[a[A[x].a[i]][j]].vis==0){
				if(xi==j||xi==0)DBfs(a[A[x].a[i]][j],ans,j);
				else DBfs(a[A[x].a[i]][j],ans+A[x].t[xi]+A[x].t[j],j);
			}
		}
	} 
	A[x].vis=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i],&t);
			A[a[i][j]].t[i]=t;
			A[a[i][j]].a[++A[a[i][j]].cnt]=i;
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		mi=INT_MAX; 
		DBfs(x,w[x]+w[y],0);
		printf("%d\n",mi); 
	}
	return 0;
} 
