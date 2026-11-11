#include<bits/stdc++.h>
using namespace std;
long long n,m,b,a[100000],ma=LLONG_MIN,mn=LLONG_MAX,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if(a[i]<mn) b=i;
		mn=min(mn,a[i]);
	}
	ans=a[1];
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		for(int i=2;i<=n;i++){
			if(i==b) continue;
			ans&=a[i];
		} 
		cout<<ans;
		return 0;
	}
	return 0;
}
