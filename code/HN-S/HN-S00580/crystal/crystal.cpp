#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+100;

long long n,m,ans=0;
long long a[N]={},dp[N]={};

long long v(long long l,long long r){
	//计算将[l,r]合并的最少能量花费
	return (dp[r]-dp[l]-(a[r]-a[l])*l); 
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++) dp[i]=dp[i-1]+i*(a[i]-a[i-1]);
	
	for(int i=0;i<n;i++){
		//分别计算以a[i]为基准最多能合并几个水晶球
		long long l=0,r=i,mid=0,ans1=1;
		while(l<=r){
			mid = (l+r)>>1;
			if(v(mid,i)<=m){
				ans1 = max(ans1,(i-mid+1));
				r = mid-1;
			}else l=mid+1;
		}
		ans = max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
