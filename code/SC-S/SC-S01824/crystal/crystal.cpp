#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;long long m;
long long a[N],sum[N];
bool check(int x){
	long long minn=9e18;
	for(int i=x;i<=n;i++){
		long long all=sum[i]-sum[i-x];
		all=a[i]*x-all;
		minn=min(minn,all);
	}
	return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	stable_sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}