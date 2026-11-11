#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+20;
ll n,m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	deque<int>q;
	ll now=0,ans=0;
	for(int i=1;i<=n;i++){
		now+=q.size()*(a[i]-a[i-1]);
		q.push_back(i);
		while(!q.empty()&&now>m){
			now-=(a[i]-a[q.front()]);
			q.pop_front();
		}
		ll sum=q.size();
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}