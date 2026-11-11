#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long dp[2005][2005];
long long n,k;
long long dfs(long now,long cnt){
	if(cnt>n){
		return now;
	}
	long long maxx=0,ans=0;
	for(int i=cnt;i<=n;i++){
		maxx=max(maxx,(now&a[i]));
		if(cnt!=1){
			ans=max(ans,dfs(maxx,cnt+1));
		}
		else{
			ans=max(ans,dfs(a[i],cnt+1));
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	else if(k==n-1){
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt&=a[i];
		}
		long long maxx=0; 
		for(int i=1;i<=n;i++){
			maxx=max(maxx,(cnt&a[i]));
		}
		cout<<maxx;
		return 0;
	}
	else if(k==n){
		int cnt=a[1];
		for(int i=2;i<=n;i++){
			cnt&=a[i];
		}
		cout<<cnt;
	}
	else{
		cout<<dfs(0,1);
	}
	return 0;
} 
