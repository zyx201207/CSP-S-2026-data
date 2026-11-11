#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int M=500005,N=505;
long long c,n,m,d,q,w[M],a[N],t[N],mp[1005][1005],k,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(mp,0x3f,sizeof(mp));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[j],&t[j]);
			mp[a[j]][i+m]=mp[i+m][a[j]]=t[j];
		}
	}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				if(i!=j&&j!=k){
					mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		printf("%d\n",w[x]+w[y]+mp[x][y]);
	}
	return 0;
}
