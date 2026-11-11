#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
#define N 500005
int a[N];
int cf[N];
bool check(int x){
	int now=0;
	for(int i=1;i<x;i++){
		now+=cf[i]*i;
	}
	if(now<=m) return true;
	for(int i=x;i<n;i++){
		now-=(a[i]-a[i-x+1]);
		now+=cf[i]*x;
		if(now<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) cf[i]=a[i+1]-a[i];
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+((r-l)>>1);
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}
