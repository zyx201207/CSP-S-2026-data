#include<bits/stdc++.h>
using namespace std;

long long n,m,a[1000000],sm=0,mx=0,mxf=0,sum[1000000],mins;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sm+=a[i];
		mx=max(mx,a[i]);
	}
	if(m>=mx*n-sm){
		cout<<n;
		return 0;
	}
	sort(a,a+n+1);
	if(n>1){
		mins=a[2]-a[1];
		
		for(int i=1;i<=n;i++){
			if((a[n]-a[i])*(n-i+1)/2<=m){
				mxf=max(mxf,n-i+1);
				break;
			}
		}
		
		
		cout<<mxf;
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			if((r-l)*a[r]-sum[r-1]+sum[l-1]<=m){
				mxf=max(mxf,r-l+1ll);
			}
		}
	}
	cout<<mxf;
	
	return 0;
}
