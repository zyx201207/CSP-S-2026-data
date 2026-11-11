#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,m,a[500010],ans[300010];
map<ll,ll> mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	bool b=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]=i;
		if(a[i]<a[i-1])b=0;
	}
	if(b){
		for(ll i=1;i<=m;i++)
			cout<<mp[i]<<' ';
		return 0;
	}
	for(ll i=1;i<=n;i++){
		stack<ll> s;
		map<ll,bool> mp;
		for(ll j=i;j<=n;j++){
			if(mp[a[j]]){
				while(s.top()!=a[j]){
					mp[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				mp[a[j]]=1;
			}
		}
		for(auto i:mp)if(i.second)ans[i.first]++;
	}
	for(ll i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
