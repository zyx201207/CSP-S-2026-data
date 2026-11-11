#include<bits/stdc++.h>
#define int long long
using namespace std;
int pre[500100],ans,n,m,a[500100];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(x*a[i]-pre[i]+pre[i-x]<=m){
			return true;
		}
	}
	return false;
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
		pre[i]=pre[i-1]+a[i];
	}
	int l=1,r=500100;
	while(l<=r){
		int mid=(l+r)/2;
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
