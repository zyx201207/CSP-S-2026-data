#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,int>
const int N=2e5+5;
pii a[N];
ll vis[N],n,m,dp[N];
int num_two(ll n){
	int cnt=0;
	while(n>0){
		cnt+=n%2;
		n/=2;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		a[i].second=num_two(a[i].first);
	}
	for(int i=1;i<=n;i++){
		dp[i]=a[i].second;
	}
	ll num=0,mx=0;
	for(int i=1;i<=m;i++){
		ll tnum=0,tmx=0,tid=0;
		for(int j=1;j<=n;j++){
			if(i==1) num=a[j].first;
			if(vis[j]){
				dp[j]=0;
				continue;
			} 
			dp[j]=num&a[j].first;
			int dpnum=num_two(dp[j]);
			if(dpnum>tmx){
				tmx=dpnum;
				tnum=dp[j];
				tid=j;
			}
		}
		num=tnum,mx=tmx,vis[tid]=1;
	}
	ll mxn=0;
	for(int i=1;i<=n;i++){
		mxn=max(mxn,dp[i]);
	}
	cout<<mxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
