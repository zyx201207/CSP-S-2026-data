#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],dp[20005][20005],maxx=-3;
int dfs(int x,int m){
	if(x>n){
		if(m<k||m>k){
			return 0;
	    }else{
			return 1073741823;
		}
    }
    if(dp[x][m]!=-1){
		return dp[x][m];
	}
    int maxn=0;
    maxn=max(maxn,dfs(x+1,m));
    maxn=max(maxn,(dfs(x+1,m+1)&a[x]));
    return dp[x][m]=maxn;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(k==1){
		cout<<maxx;
		return 0;
    }
    if(k==2){
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
				//cout<<ans<<endl;
			}
	    }
	    cout<<ans;
	    return 0;
	}
    if(k==n){
		int y=a[1];
		for(int i=2;i<=n;i++){
		    y=(y&a[i]);
	    }
	    cout<<y;
	    return 0;
	}
	cout<<dfs(1,0);
	return 0;
}
//1073741823
