#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],c[500005],vis[300005],ans[300005];
stack<ll>stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		for(ll j=i;j<=n;j++){
			if(vis[a[j]]){
				while(stk.top()!=a[j]){
					vis[stk.top()]--;
					stk.pop();
				}
			}
			else stk.push(a[j]),vis[a[j]]++;
		}
		while(!stk.empty()){
			ans[stk.top()]++;
			stk.pop();
		}
	}
	for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
