#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
int n,m,a[500005],s[500005];
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		if(a[i+x-1]*x-s[i+x-1]+s[i-1]<=m){
			return 1;
		}
	}
	return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
} 
