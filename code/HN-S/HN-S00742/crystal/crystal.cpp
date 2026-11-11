#include<bits/stdc++.h>
using namespace std;
#define int long long
long long n,m,a[5555555],s[555555];
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int k=a[3]-a[2];
	m/=k;
	for(int i=1;i<=n;i++){
		a[i]=i;
		s[i]=a[i]+s[i-1];
	}
	int l=1,r=n,mid=(l+r)/2;
	while(l<r){
		mid=(l+r)/2;
		if(s[mid]>m)r=mid;
		else if(s[mid]<m)l=mid;
		if(s[mid]==m){
			cout<<mid+1;
			return 0;
		}
		if(l+1==r){
			cout<<r;
			return 0;
		}
	}
	return 0;
}

