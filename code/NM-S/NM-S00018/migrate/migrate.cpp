#include<iostream>
#include<algorithm>
using namespace std;
const int MAXD=2000000000000000005,MAXN=2000005;
long long c,T,n,d,x[MAXN],tx[MAXN],ans;
void dfs(long long now){
	tx[now]++;
	for(long long k=1;k<=d&&now+k<x[n] ;k++)dfs(now+k);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		ans=0;
		for(long long j=1;j<n;j++){
			for(int i=1;i<=x[n];i++)tx[i]=0;
			dfs(j);
			for(int i=1;i<=x[n];i++)if(tx[i]==2)ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
申必题目
下楼梯，一次最多下n个，求有多少对楼梯之间有且仅有两种下法
数据量是16^6 不好暴力啊~~很气 
x数组是严格递增的 很好 
二维数组MAXN真的不会爆内存吗~~
桶在每个点统计时都用上就好了~~ 
?怎么爆了 
*/
