#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a,b,c) for(int a=(b);a<=(c);++a)
#define per(a,b,c) for(int a=(b);a>=(c);--a)
const int N=5e5+5;
int n;
ll m;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	priority_queue <ll,vector<ll>,greater<ll> > pq;
	ll sum=0;
	int ans=0;
	rep(i,1,n){
		sum+=(ll)pq.size()*(a[i]-a[i-1]);
		while(sum>m&&!pq.empty()) sum-=a[i]-pq.top(),pq.pop();
		pq.push(a[i]);
		ans=max(ans,(int)pq.size());
	}
	cout<<ans<<'\n';
	return 0;
}
