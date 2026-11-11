#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
ll a[500005],b[500005];
ll m,usedx;
int n,mx,sm;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	mx=1;
	a[0]=0;b[0]=0;
	std::sort(a+1,a+n+1);
	//std::cerr<<"t0ok";
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	//std::cerr<<"t1ok";
	for(int i=1;i<=n;i++){
		usedx=0;
		int l=i+1,r=n,mid;
		while(l<=r){
			mid=l+(r-l)/2;
			ll x=(mid-i+1)*a[mid]-(b[mid]-b[i-1]);
			if(x>m) r=mid-1;
			else l=mid+1;
		}
		if(r-i+1>mx) mx=r-i+1;
	}
	std::cout<<mx;
	return 0;
}