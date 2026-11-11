#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],s[500010],tl,tr,sum;
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int l=i,r=i+x-1;
		if(a[r]*x-(s[r]-s[l-1])<=m){
			tl=l;
			tr=r;
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
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=0,r=n,mid,ans=-1;
	while(l<=r){
		mid=(l+r)/2;
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
