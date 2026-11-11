//SN-J00840 谢俊哲 西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<ll>> dp;//dp[i][j] ->从后往前第i个数加入时合并后 j的出现 
vector<ll> a,ans;
vector<bool> vis;
ll n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	//cin<< cout>> 能看到吗？这题样例四输出是乱码，根本看不了,甚至我的输出也是一模一样的乱码！ (这算是对了吗？) 
	//好吧第一次遇到是乱码的情况，就这样吧 
	a.resize(n+1);
	ans.resize(m+1,0);
	dp.resize(n+1,vector<ll>(m+1,0));
	vis.resize(m+1,false);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		if(!vis[a[n-i+1]]){
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[i-1][j];
				ans[j]+=dp[i][j];
			}
			++dp[i][a[n-i+1]];
			++ans[a[n-i+1]];
			/*
			for(int j=1;j<=m;j++){
				printf("%lld ",dp[i][j]);
			}
			printf("\n");
			*/
		}else{
			ll flag=n;
			while(a[n-i+1]!=a[flag]) flag--;
			for(int j=1;j<=m;j++){
				dp[i][j]=dp[n-flag+1][j];
				ans[j]+=dp[i][j];
			}
			/*
			for(int j=1;j<=m;j++){
				printf("%lld ",dp[i][j]);
			}
			printf("\n");
			*/
		}
		vis[a[n-i+1]]=1;
	}
	for(int j=1;j<=m;j++){
		printf("%lld ",ans[j]);
	}//orz rp++ 我真的不知道该怎么优化了qwq 下午场加油 
	return 0;
}
