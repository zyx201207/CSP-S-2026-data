#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[(int)2e6+10];
int s[(int)2e6+10];
int check(int x){
	for(int i=0;i+x<=n;i++){
		int j=i+x;
		if(s[j]-s[i]-x*a[i+1]<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//a[i]=-a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=0;i<=n;i++){
		int l=0,r=i-1;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-s[i]+s[mid]<=m)r=mid;
			else l=mid+1;
		}
		if(a[i]*(i-l)-s[i]+s[l]<=m)ans=max(ans,i-r); 
	}
	cout<<ans;
	/*int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
	//	cout<<check(mid)<<' '<<l<<' '<<r<<' '<<mid<<'\n'; 
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;*/
//	for(int i=1;i<=n;i++){
		
//	}
    return 0;
}/*4 3
-1 2 3 5*/