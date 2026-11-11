#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int ans;
long long a[500010];
long long b[500010];
long long check(int x){
	long long minn=1e18;
	int l=0;
	long long sum=0;
	for(int i=1;i<x;i++){
		sum+=(a[x]-a[i]);
	}
	minn=sum;
	l=1;
	for(int i=2;i+x-1<=n;i++){
		sum=(a[i+x-1]*(x-1)-(b[i+x-2]-b[i-1]));
		if(sum<minn){
			minn=sum;
			l=i;
		}
	}
	long long now=0;
	for(int i=l;i<=l+x-1;i++){
		now+=(a[l+x-1]-a[i]);
	}
	return now;
}
int main(){
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
		b[i]=b[i-1]+a[i];
	}
	int l=1;
	int r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)<=m){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}