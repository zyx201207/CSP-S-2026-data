#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,mx,maxn,sum,f=1;
int a[N];
const int M=1e4+5;
int dp[M][M];
int dp2[N];
void dfs(int now,int ans,int cnt,int f){
	if(now>n){
		if(cnt==m){
			mx=max(mx,ans);
		}
		return;
	}
	dfs(now+1,ans,cnt,f);
	if(f==0){
		dfs(now+1,a[now],cnt+1,1);
	}else{
		dfs(now+1,ans&a[now],cnt+1,1);
	}
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	maxn=max(maxn,a[i]);
    	sum=(sum==0?a[i]:a[i]&sum);
	}
	if(m==1){
		mx=maxn;
	}else if(m==n){
		mx=sum;
	}else if(n<=20){
		dfs(1,0,0,0);
	}else if(n<=2000 && m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}		
	}else if(n<=10000){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				dp[i][j]=max(dp[i-1][j],(dp[i-1][j-1]==0?a[i]:dp[i-1][j-1]&a[i]));
			}
		}
		mx=dp[n][m];
	}else if(n<=200000){
		
	}
	cout<<mx;
    return 0;
}
