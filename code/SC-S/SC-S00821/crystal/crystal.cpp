#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int l=1,r,ans=1;
int a[500005],s[500005],mx[500005];
int f(int x){
	int k=1e18;
	for(int i=x;i<=n;i++){
		k=min(k,abs(a[i]*x-(s[i]-s[i-x])));
	}
	return k;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	while(l<=r){
		int mid=(l+r)/2;
		if(f(mid)>m){
			r=mid-1;
		}
		else{
			l=mid+1;
			ans=max(ans,mid);
		}
	}
	cout<<ans;
	return 0;
}