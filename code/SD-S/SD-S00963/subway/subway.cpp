#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N],k[N],dp[5005][5005];
vector<int>a[N],t[N];
void floyd(){
	for(int x=1;x<=m;x++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][x]+dp[x][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f3f3f3f,sizeof(dp));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int xxx,yyy;
			scanf("%d%d",&xxx,&yyy);
			a[i].push_back(xxx);
			t[i].push_back(yyy);
		}
		for(int j1=1;j1<=k[i];j1++){
			for(int j2=1;j2<=k[i];j2++){
				if(j1==j2) continue;
				int k1=a[i][j1],k2=a[i][j2];
				dp[k1][k2]=min(dp[k1][k2],t[i][j1]+t[i][j2]);
			}
		}
	}
	floyd();
	while(q--){
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		printf("%d\n",w[xx]+w[yy]+dp[xx][yy]);
	}
	return 0;
}
