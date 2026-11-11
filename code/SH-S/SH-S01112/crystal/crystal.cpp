#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=100){
		ll a[101];
        ll dp[101][101];  
		for(int i=0;i<n;i++)   cin>>a[i];
	    for(int i=0;i<n;i++)   dp[i][i]=0;
	    for(int i=0;i<n-1;i++)   dp[i][i+1]=abs(a[i+1]-a[i]);
    	for(int len=3;len<=n;len++){
		    for(int i=0;i+len-1<n;i++){
			    int j=i+len-1;
			    long long maxn=-1e18;
			    for(int k=i;k<=j;k++)   maxn=max(maxn,a[k]);
			    for(int k=i;k<=j;k++)   dp[i][j]+=abs(maxn-a[k]);
		    }
	    }
	    long long ans=0;
	    for(int i=0;i<n;i++){
		    for(int j=i;j<n;j++){
			    if(dp[i][j]<=m){
				    if((j-i+1)>ans)   ans=j-i+1;
			    }
		    }
	    }
	    cout<<ans;
	    return 0;
	}
	int minus;
	int a,b;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(i==n-1)   a=x;
		if(i==n)   b=x;
	}
	minus=b-a;
	cout<<floor(sqrt(2*m/minus));
	return 0;
	fclose(stdin);
	fclose(stdout);
}
