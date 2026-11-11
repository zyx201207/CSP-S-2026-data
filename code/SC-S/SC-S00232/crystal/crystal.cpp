#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500005];
bool check(int mid,int n,ll m){
	ll total=0;
	for(int i=1;i<=n;i++){
		total+=a[i];
		if(i>=mid){
			if(mid*a[i]-total<=m)return true;//没有超longlong
			else{total-=a[i-mid+1];}
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n;ll m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,n,m)){
			ans=max(ans,mid);
			l=mid+1;
		}
		else{r=mid-1;}
	}
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/