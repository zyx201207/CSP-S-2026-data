#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int n;
long long m;
long long sum=0,ans=1;
long long pd(int mid){
	long long spd=0,minn=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<mid;i++){
		spd+=(a[i+1]-a[i])*i;
	}
	minn=min(minn,spd);
	for(int i=1;i<=n-mid;i++){
		spd-=(a[mid+i-1]-a[i]);
		spd+=(a[mid+i]-a[mid+i-1])*(mid-1);
		minn=min(minn,spd);
	}
	return minn;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(pd(mid)>m){
			r=mid-1;
		}
		else{
			l=mid;
		}
	}
	cout<<l;
	return 0;
}
