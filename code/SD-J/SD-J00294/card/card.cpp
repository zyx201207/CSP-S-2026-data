#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,n,m,a[200005],ans[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=n;i>=1;i--){
		if(ans[a[i]]==0){
			ans[a[i]]=i;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
