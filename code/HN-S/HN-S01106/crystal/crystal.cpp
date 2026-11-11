#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,dp[N];
long long m,a[N];
priority_queue<int,vector<int>,greater<int> >qu;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=0;
	long long k=0;
    for(int i=1;i<=n;i++){
    	while(k+qu.size()*(a[i]-a[i-1])>m){
    		k-=(a[i-1]-qu.top());
    		qu.pop();
		}
    	dp[i]=qu.size()+1;
    	k+=qu.size()*(a[i]-a[i-1]);
	    qu.push(a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(dp[i],ans);
	}
	cout<<ans;
	return 0;
} 
