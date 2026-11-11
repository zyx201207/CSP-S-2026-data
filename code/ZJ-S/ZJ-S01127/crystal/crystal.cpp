#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],k,s[500005],l,r,mid,ans,f;
bool check(int x){
	f=0;
	for(int i=x;i<=n;i++){
		if((s[i]-s[i-x]-(a[n]-a[i])*(x-1))<=m){
			f=1;break;
		}
	}
	return f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+a[n]-a[i];
	}
	l=0,r=n,mid=(l+r)/2;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
