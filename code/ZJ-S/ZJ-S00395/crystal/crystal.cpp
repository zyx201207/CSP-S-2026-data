#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m;
ll sum;
int a[N];
ll l=1,r=5e5;
ll ans;
bool check(int x){
	if(x>n)return 0;
	sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[x]-a[i];
	}
	for(int i=x;i<=n;i++){
		if(sum<=m)return 1;
		sum+=(a[i+1]-a[i])*x;
		sum-=a[i+1]-a[i-x+1];
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}