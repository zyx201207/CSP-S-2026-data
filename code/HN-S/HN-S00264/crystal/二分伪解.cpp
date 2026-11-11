#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
bool check(int mid){
	unsigned int res=0;
	for(int i=1;a[i]<mid;i++){
		res+=(mid-a[i]);
		if(res>m)return 0;
	}
	return res<=m;
	
}
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int mx=-1e18,mn=1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	int l=mn,r=2*mx;
	int mid=(l+r)>>1;
	int ans=0;
	sort(a+1,a+n+1,cmp);
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
		
	}
	cout<<upper_bound(a+1,a+n+1,ans)-a-1;
}
/*
5 8
-3 -1 2 2 7
410*/
