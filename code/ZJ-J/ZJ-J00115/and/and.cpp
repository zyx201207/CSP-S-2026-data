#include<bits/stdc++.h> 
using namespace std;
long long n,m,g[25],a[200005],maxa=0,maxi=0,dp[20005];
void dfs(long long x){
	if(x>m){
		long long ans=a[g[1]];
		for(long long i=2;i<=m;i++){
			ans&=a[g[i]];
		}
		maxa=max(maxa,ans);
		return ;
	}
	for(long long i=g[x-1]+1;i<=n;i++){
		g[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	bool flag=1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		long long h=a[i]+1;
		while(1){
			if(h%2==1){
				if(h!=1)flag=0;
				break;
			}
			h/=2;
		}
		maxi=max(maxi,a[i]);
	}
	if(n<=20){
		dfs(1);
		cout<<maxa;
		return 0;
	}
	if(m==1){
		for(long long i=1;i<=n;i++){
			maxa=max(maxa,a[i]);
		}
		cout<<maxa;
		return 0;
	}
	if(m==n){
		maxa=a[1];
		for(long long i=2;i<=n;i++){
			maxa&=a[i];
		}
		cout<<maxa;
		return 0;
	}
	if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				maxa=max(maxa,a[i]&a[j]);
			} 
		}
		cout<<maxa;
		return 0;
	}
	if(m==n-1){
		for(long long i=1;i<=n;i++){
			long long answ=0;
			if(i==1) answ=a[2];
			else answ=a[1];
			for(long long j=1;j<=n;j++){
				if(j!=i) answ&=a[j];
			} 
			maxa=max(maxa,answ);
		}	
		cout<<maxa;
		return 0;
	}
	if(flag){
		for(long long i=1;i<=n;i++) maxa=min(maxa,a[i]);
		cout<<maxa;
		return 0;
	}
	int kkk=0;
	dp[1]=maxi;
	for(long long i=1;i<=n;i++) if(maxi==a[i]){kkk=i;break;}
	for(long long i=1;i<=n;i++){
		for(long long j=m;j>=1;j--){
			if(i==kkk) continue;
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
} 
