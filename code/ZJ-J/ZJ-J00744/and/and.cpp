#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,M=(1<<20)+1;
int n,m,a[N],ad,mx,ans,dp[21][21];
int dfs(int u,int sum,int cnt){
//	if(m-cnt+1>n-u+1) return;
	if(sum<ans) return dp[u][cnt]=0; 
	if(u==n+1){
		if(cnt==m) return sum;
		return 0;
	}
	return dp[u][cnt]=max(max(dfs(u+1,sum,cnt),dfs(u+1,sum&a[u],cnt+1)),dp[u][cnt]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
//	n=4,m=2;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i==1) ad=a[i];
		else ad&=a[i];
		mx=max(mx,a[i]);
	}
	if(n==m){
		cout<<ad;
		return 0;
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(n<=20){
		cout<<dfs(1,INT_MAX,0);
		return 0;
	}
	if(m==2){
		int ans1=0,nd=0,nd2=0;
		for(int i=1;i<n;++i){
			nd2=a[i];
			nd=nd2;
			for(int j=i+1;j<=n;++j){
				nd&=a[j];
				ans1=max(nd,ans1);
				nd=nd2;
			}
		}
		cout<<ans1;
		return 0;
	}
	else{
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
	}
	return 0;
} 
