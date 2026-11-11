#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+10;
struct node{
	int x,y;
};
vector <node> v[N];
int k[510],a[510][N],w[N],t[510][N];
ll mint=0;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for (int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
			v[a[i][j]].push_back({i,j});
		}
	}
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		mint=0;
		for (int i=1;i<=n;i++){
			
		}
		printf("%lld\n",mint);
	}
}
