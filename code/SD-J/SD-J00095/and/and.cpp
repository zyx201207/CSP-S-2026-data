#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N=2e5+5;
ll n,m,ans,a[N];

deque<ll>q;

bool cmp(ll a,ll b){
	return a>b;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(ll i=2;i<=m;i++)q.push_back(a[i]);
	while(!q.empty()){
		ll x=q.front();
		ans&=x;
		q.pop_front();
	}
	cout<<ans;
	return 0;
}
