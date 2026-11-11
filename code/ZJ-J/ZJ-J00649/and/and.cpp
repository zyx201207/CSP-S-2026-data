#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],ans;
void yu(ll k,ll l,ll g){
	if(k>m){
		ans=max(ans,g);
		return;
	}
	for(ll i=l;i<=n-m+k;i++){
		yu(k+1,i+1,g&a[i]);
	}
}
int main(){
	freopen("and.in",r,stdin);
	freopen("and.out",w,stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	yu(1,0,0xffffffff);
	cout<<ans;
	return 0;
} 
