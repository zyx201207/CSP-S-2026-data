#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int c,n,m,d,q,w[M],s[505],e[405][405];
vector<int> a[505],t[505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		for(int j=1;j<=s[i];j++){
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			if(j==2){
				e[a[i][j-1]][a[i][j]]=t[i][j]+t[i][j-1];
				e[a[i][j]][a[i][j-1]]=t[i][j]+t[i][j-1];
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	while(q--){
		int x,y; scanf("%lld%lld",&x,&y);
		printf("%lld\n",e[x][y]+w[x]+w[y]);
	}
	return 0;
}
