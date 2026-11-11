#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500003],cf[500003];
int ans;
bool cmp(int a,int b){
	return a<b;
}
int ef(int x){
	int l=1,r=x,mid;
	while(l<r){
		mid=floor((l+r)*1.0/2);
		if(cf[x]-cf[mid]-(mid-1)*(a[x]-a[mid])<=m) r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++) cf[i]=cf[i-1]+(i-1)*(a[i]-a[i-1]);
//	cout<<cf[n]<<"\n";
//	for(int i=1;i<=n;i++) cout<<cf[i]<<" ";
//	cout<<"\n";
	for(int i=1;i<=n;i++){
		int j=ef(i);
//		cout<<i<<" "<<j<<"\n";
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
/*
5 431
213 81 69 432567 57
3
*/