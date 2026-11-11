//李思齐 西安爱之中学 SN-J00322 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n=0,a[501000]={},m,dp[501000],maxn=0;
bool cmp(ll a,ll b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		sort(a+1,a+1+n,cmp);
		for(int i=2;i<=n;i++){
			dp[i]=a[i]-a[i-1]+dp[i-1];
			cout<<dp[i];
		}
		for(int i=2;i<=n;i++){
			ll cnt=0,ids=i;
			while(cnt<=m&&ids<=n+1){
				cnt=cnt+(ids-i+1)*(a[ids]-a[ids-1]);
				ids++;
			}
			cout <<ids-i<<"\n";
			maxn=max(maxn,ids-i);
		}
		cout<<maxn;
	}else{
		if(a[1]==1&&a[2]==2){
			ll i=1,cnt=m;
			while(cnt>=0){
				cnt-=i;
				i++;
			}
			cout<<min(i,n);
		}else if(a[2]-a[1]==a[3-a[2]]){
			sort(a+1,a+1+n,cmp);
			ll i=a[2]-a[1],cnt=m;
			while(cnt>=0){
				cnt-=i;
				i+=a[2]-a[1];
			}
			cout<<min(i,n);
		}
	}
	return 0;
} 
/*
5 5 
1 2 4 8 9
5 8 
-3 -1 2 2 7 
10 999
1 2 3 4 5 6 7 8 9 10
7 6
-1 -3 -5 -7 -9 -11 -13
*/
