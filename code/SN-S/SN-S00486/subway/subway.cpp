#include <bits/stdc++.h>

using namespace std;
int c,n,m,d,q;
const int N=501,M=4e5+10,Q=1e5+10;
struct Node{
//	int node;
	int dui[N];
	int h_chen[N];
}g[M];
struct Dt{
	int bgn;
	int ed;
}set_plan[Q];
//bool st[M];
//int dist[M];
int price[M];
int xn[M];
//long long value;
long long dp[M];
int num[M];
//李星宇 SN-S00486 陕西省西安中学 
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway1.out","w",stdout);	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&price[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		for(int j=1;j<=num[i];j++){
			int a,t;
			scanf("%d%d",&a,&t);
			g[a].h_chen[i]=t;
			xn[j]=a;
		}
		for(int j=1;j<=num[i]-1;j++){
			g[xn[j]].dui[i]=xn[j+1];//g[].dui[j]指点的对应点 
		}
	}
	for(int i=1;i<=q;i++){
		int a1,b1;
		scanf("%d%d",&a1,&b1);
		set_plan[i].bgn=a1;
		set_plan[i].ed=b1;
	}
	
	for(int i=1;i<=q;i++){
		dp[set_plan[i].bgn]=price[set_plan[i].bgn];
//		value+=price[set_plan[i].bgn];
		int bi=set_plan[i].bgn;
		for(int j=1;j<=n;j++){//i为第几组计划，j为第几组线路， k为点个数
			int dot=g[bi].dui[j];//dot为下一个点 ，last为当前点
			int last=bi;
//			cout<<last<<"->"<<dot<<endl;
			for(int k=1;k<=num[j];k++){
//				dp[last]=dp[dot];
				if(g[dot].h_chen[j]!=0){
					bi=dot;
					dp[dot]=min(dp[last],dp[dot]+g[last].h_chen[j]+price[dot]);
					continue;			
				}
				else{
					dp[dot]=dp[last];							
				}
//				cout<<dp[dot]<<" "<<dp[last]<<"||"<<last<<"->"<<dot<<endl;
				last=dot;
				dot=g[dot].dui[j];
				if(dot==0){
					break;
				}					
			}
		}
		long long result=dp[set_plan[i].ed]+price[set_plan[i].ed];
		printf("%lld\n",result);
	} 
	return 0;
}
