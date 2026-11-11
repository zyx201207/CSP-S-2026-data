#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll vis[300005];
ll d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		deque<ll>st;
		for(ll j=1;j<=m;j++)vis[j]=0;
		for(ll j=i;j<=n;j++){
			st.push_back(a[j]);
			if(vis[a[j]]==1){
				st.pop_back();
				while(st.back()!=a[j])vis[st.back()]=0,st.pop_back();
			}
			vis[a[j]]=1;
		}
		while(!st.empty()){
			d[st.back()]++;
			st.pop_back();
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
