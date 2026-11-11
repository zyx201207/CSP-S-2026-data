#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,r,mid,idx,idx2,a[500005],sum[500005];
int get(int l,int r){
	if(l>r){
		return 0;
	}
	return sum[r]-sum[l-1];
}
bool check(int x){
	for(int i=x;i<=n;i++){
		int l=i-x+1,r=i;
		if(a[r]*(r-l+1ll)-get(l,r)<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;//³¤¶È 
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
} 
