#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[500005], card[300005], ans[300005], to[300005], in[300005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(ll i=1; i<=n; i++)cin >> a[i];
	for(ll i=n; i>=1; i--){
		if(card[a[i]]==0)card[a[i]]=i;
	}
	for(ll i=1; i<=m; i++){
		to[i]=a[card[i]+1], card[i]=0, in[to[i]]++;
	}
	for(ll i=1; i<=n; i++){
		ans[a[i]]++;
	}in[0]=1e9;
	queue<ll>que;
	for(ll i=1; i<=m; i++){
		if(in[i]==0)que.push(i);
//		cout<<i<<':'<<in[i]<<'\n';
	}
//	cout<<'\n';
	while(que.size()){
		ll tp=que.front(), v=to[tp];que.pop();
		if(--in[v]==0)que.push(v);
		ans[v]+=ans[tp];
	}
	for(ll i=1; i<=m; i++)cout<<ans[i]<<' ';
	return 0;
}

