#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],l,r;
bool check(int mid){
	int s=0;
	for(int i=1;i<=mid;i++){
		s+=a[mid]-a[i];
	}
	for(int i=mid;i<=n;i++){
		if(s<=m){
			return 1;
		}
		s-=a[i]-a[i-mid+1];
		s+=(mid-1)*(a[i+1]-a[i]);
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)==1){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}