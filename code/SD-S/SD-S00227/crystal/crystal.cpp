/*
maybe we can use 二分
because 一个长度为m，以i结尾的区间可行:(m-1)*a[i]-(s[i-1]-s[i-m]) <=m
*/
//freopen!!!
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,a[N],m,s[N];
bool check(int mid){
	for(int i=mid;i<=n;i++){
		if((mid-1)*a[i]-(s[i-1]-s[i-mid])<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
}
