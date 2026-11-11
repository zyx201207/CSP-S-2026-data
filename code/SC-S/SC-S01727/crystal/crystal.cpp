#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],s[500010],ans=1;
int check(int x){
	for(int i=x;i<=n;i++){
		int t=s[i]-s[i-x];
		int sm=a[i]*x;
		if(sm-t<=m)return 1;
	}
	return 0;
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
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(r-l)/2+l;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
