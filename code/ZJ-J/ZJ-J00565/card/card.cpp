#include <iostream>
#include <cstdio>
#include <stack>
#include <map>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
stack<ll>st;
map<ll,bool>mp;
map<ll,ll>ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for (ll i=1;i<=n;i++){
		for (ll j=i;j<=n;j++){
			if (!mp[a[j]]){
				mp[a[j]]=1;
				st.push(a[j]);
			}else{
				while (!st.empty()){
					ll k=st.top();
					st.pop();
					mp[k]=0;
					if (k==a[j]){
						break;
					}
				}
				st.push(a[j]);
				mp[a[j]]=1;
			}
		}
		while (!st.empty()){
			ll cnt=st.top();
			st.pop();
			ans[cnt]++;
			mp[cnt]=0;
		}
	}
	cout<<ans[1];
	for (ll i=2;i<=m;i++){
		cout<<" "<<ans[i];
	}
	return 0;
}
