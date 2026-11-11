#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
int l,r,mid,ans;
bool check(){
	for(int i=1;i<=n-mid+1;i++){
		int idx=(i+i+mid-1)/2;
		int need=0;
		for(int j=i;j<idx;j++){
			need+=(a[idx]-a[j]);
		}
		for(int j=idx+1;j<idx+mid;j++){
			need+=(a[j]-a[idx]);
		}
		if(need<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	int les=a[2]-a[1];
	bool f_les=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=les){
			f_les=0;
			break;
		}
	}
	if(f_les){//是等差数列 
		int cnt=0;
		int i;
		for(i=1;i<=n-1;++i){
			if(cnt+i*les<=m){
				cnt+=i*les;
			}else{
				break;
			}
		}
		cout<<i;
		return 0;
	}
	l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check()){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
