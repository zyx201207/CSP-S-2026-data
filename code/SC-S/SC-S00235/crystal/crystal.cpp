#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ff[500005];
bool check(int x){
	for(int i=x;i<=n;i++){
		int o=ff[i]-ff[i-x],p=a[i]*x;
		if(p-o<=m){
			return 1;
		}
	}
	return 0;
}
int f(int l,int r){
	while(l<=r){
//		cout<<l<<" "<<r<<"\n";
		int mid=l+(r-l)/2;
		if(check(mid)==1){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return r;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ff[i]=a[i]+ff[i-1];
	}
	cout<<f(1,n);
	return 0;
}
