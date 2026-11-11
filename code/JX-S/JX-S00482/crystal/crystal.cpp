#include<bits/stdc++.h>
using namespace std;
long long k,n,a[500015],f[500005];
bool find(int x){
	for(int i=x;i<=n;i++){
		if(((x-1)*a[i]-(f[i-1]-f[i-x]))<=k) {
			return true;
		}
	}
	return false;
}
int search(){
	int l=1,r=n,mid;
	while(l<r){
		mid=l+(r-l+1)/2;
		if(find(mid)) l=mid;
		else r=mid-1;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	f[0]=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	cout<<search();
	return 0;
}
