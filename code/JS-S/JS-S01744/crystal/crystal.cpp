#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000010],s[1000010],m;
int aa(int x){
	for(int i=x;i<=n;i++){
		if((a[i]*x-s[i]+s[i-x])<=m){
			return 1;
		}
	}
	return 2;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(r+l)/2;
		if(aa(mid)==1){
			l=mid+1;
		}else r=mid;
	}
	cout<<l-1;
	return 0;
}
