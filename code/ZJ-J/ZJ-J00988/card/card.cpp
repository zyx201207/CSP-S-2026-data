#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=5e5+9;
ll n,m,a[N],ans[N],t,last[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
	}
	for(ll i=1;i<=n;i++){
		t-=ans[a[i]];
		ans[a[i]]=max(ans[a[i]],i-t);
		if(last[a[i]]!=i) t+=ans[a[i]];
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
