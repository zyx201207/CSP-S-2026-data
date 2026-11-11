#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500005
ll n,m,cnt;
ll a[N];
deque<ll>q;
bool f;
__int128 sum;
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	q.push_back(a[1]);
	for(ll i=2;i<=n;i++){
		ll x=q.back();
		ll sz=q.size();
		__int128 kk=(a[i]-x)*sz;
		if(sum+kk>m){
			cnt=max(cnt,sz);
			while(sum+kk>m&&!q.empty()){
				sum=sum-(a[i]-q.front());
				q.pop_front();
			}
		}
		if(sum+kk>m) break;
		sum+=kk;
		q.push_back(a[i]);
	}
	cout<<cnt;
	return 0;
}