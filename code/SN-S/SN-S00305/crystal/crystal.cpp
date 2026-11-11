#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define dep(i,a,b) for(int i=(a);i>=(b);i--)
#define endl '\n'
using namespace std;
const int maxn=5e5+7;
unsigned long long n,m;
ll a[maxn],ca[maxn];
ll dp[5007][5007];

ll ans5000(){
	ll ans=-0x3f3f3f3f3f3f3f3f;
	rep(i,1,n)dp[i][i]=ca[i];
	rep(l,1,n){
		rep(r,l+1,n){
			ll len=r-l+1;
			dp[l][r]=dp[l][r-1]+ca[r]*len;
			if(dp[l][r]<=m)ans=max(ans,len);
		}
	} 
	return ans+1;
} 

ll ansmax(){
	ll d=ca[2];
	ll l=1,r=maxn;
	unsigned long long mid;
	while(l<r){
		mid=(r-l)/2+l;
		ll ret=(d)*mid*(mid+1)/2;
		if(ret>m){
			r=mid-1;	
		}
		else{
			l=mid+1;	
		} 
	}
	return l;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	rep(i,1,n-1)ca[i]=a[i+1]-a[i];
	if(n<=5000){
		cout<<ans5000();
	}else{
		cout<<ansmax();
	}
	return 0;
}
//锁定提交求ac ac ac ac ac ac ac ac ac  
