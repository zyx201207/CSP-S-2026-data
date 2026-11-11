#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005];
bool flag=1;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		if(flag&&d[i]!=d[i-1]){
			flag=0;
		}
	}
	if(flag){
		for(long long i=1;i<=n;i++){
			long long k=d[2]*i;
			k*=i;
			if(k>m){
				ans=i-1;
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int l=1;l<n;l++){
		int tot=0;
		int r=l+1;
		for(;r<=n;r++){
			if(tot+d[r]*(r-l+1)<=m)
			{
				tot+=d[r]*(r-l+1);
			}
			else break;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0
}
