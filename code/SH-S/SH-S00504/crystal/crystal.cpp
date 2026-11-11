// Oct31==Dec25?

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int N = 500050;
int n;
ll m;
ll a[N];

bool solve(int tgt){
	ll remain = m;
	priority_queue<int, vector<int>, greater<int>> pq;
	ll last = a[1];
	
	for(int i=1;i<=n;++i){
		remain -= 1ll*pq.size()*(a[i]-last);
		pq.push(a[i]);
		while(remain<0){
			remain+=a[i]-pq.top();
			pq.pop();
		}
		last=a[i];
		if(pq.size()>=tgt) return true;
	}
	
	return false;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1, a+1+n);
	
	int L=0,R=n,ans=0;
	while(R>=L){
		int mid=(R+L)/2; // floor
		if(solve(mid)){
			ans=max(ans,mid);
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	cout<<ans;
	
	return 0;
}

