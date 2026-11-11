#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M],k[N],t[M][N];
bool a[M][N];
int dp[N][N];
//int ans;
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q; 
void f(int x,int y);
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
//	int a1;
//	for(int i=1;i<=n;i++){
//		scanf("%d",&k[i]);
//		for(int j=1;j<=k[i];j++){
//			scanf("%d",&a1);
//			scanf("%d",&t[a1][i]);
//			a[a1][i]=1;
//		}
//	}
//	memset(dp,0x3f3f3f,sizeof(dp));
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(i==j)continue;
//			for(int k=1;k<=m;k++){
//				if(a[k][i]&&a[k][j])continue;
//				dp[i][j]=min(dp[i][j],t[k][i]+t[k][j]);
//				dp[j][i]=dp[i][j];
//			}
//		}
//	}
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
//			}
//		}
//	}
	int x,y;
	int ans=0;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++){
			if(a[x][i]&&a[y][i]){
				ans+=t[x][i]+t[y][i];
			}
		}
		if(ans==0){
			for(int i=1;i<=n;i++){
				if(a[x][i]){
					ans+=t[x][i];
				}
				if(a[y][i]){
					ans+=t[y][i];
				}
			}
		}
		ans+=w[x]+w[y];
		printf("%d%d",ans);
//		f(x,y);
//		printf("%d",dp[x][y]+w[x]+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//void f(int x,int y){
//	q.push({0,x});
//	pair<int,int> c;
//	ans=pow(2,31)-1;
//	int ma;
//	while(!q.empty()){
//		c=q.top();
//		if(c.second==y){
//			ans=min(ans,c.first);
//		}
//		q.pop();
//	    ma=pow(2,31)-1;
//		for(int j=1;j<=n;j++){
//			if(c.second==j)continue;
//			for(int i=1;i<=m;i++){
//				if(a[i][c.second]&&a[i][j]){
//					ma=min(ma,t[i][c.second]+t[i][j]);
//				}
//			}
//			q.push(j,ma);
//		}
//	}
//}