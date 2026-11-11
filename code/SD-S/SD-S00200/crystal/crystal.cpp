#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001],n,m,c[500001];
bool check(int mid){
	for(int i=1;i+mid-1<=n;i++){
		int j=i+mid-1;
		if(a[j]*mid-c[j]+c[i-1]<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	int l=0,r=n+1;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
