#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500100],ans,s[500100];
int check(int x){
	for(int i=x;i<=n;i++){
		int t=a[i]*x;
		if(t<=m+s[i]-s[i-x]) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal4.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

