#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
ll a[N],ans=0;
stack<ll> st;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll i,j,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=n;i>=1;i--){
		st.push(a[i]);
	}
	map<ll,ll> ans;
	for(i=1;i<=n;i++){
		map<ll,ll> mp;
		stack<ll> p;
		stack<ll> st1;
		while(!st.empty()){
			p.push(st.top());
			if(mp[p.top()]==0){
				mp[p.top()]=1;
			}else{
				ll t=p.top();
				p.pop();
				while(!p.empty()&&p.top()!=t){
					mp[p.top()]=0;
					p.pop();
				}
			}
			st1.push(st.top());
			st.pop();
		}
		for(j=1;j<=m;j++){
			if(mp[j]==1){
				ans[j]++;
			}
		}
		while(!st1.empty()){
			st.push(st1.top());
			st1.pop();
		}
		st.pop();
	}
	for(i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

