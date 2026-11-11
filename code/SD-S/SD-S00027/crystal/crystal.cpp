#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],l=1,r,mid;
bool check(int x){
	for(int i=1; i<=n-x+1; ++i){
		if(x*a[i+x-1]-sum[i+x-1]+sum[i-1]<=m){
			return true;
		}
	}
	return false;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; ++i){
		sum[i]=sum[i-1]+a[i];
	}
	r=n;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid))	l=mid;
		else	r=mid-1;
	}
	cout<<l<<'\n';
	return 0;
}

