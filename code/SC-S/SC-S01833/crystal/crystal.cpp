#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m;
vector <ll> a;

ll search(const vector <ll>& t){
	ll cur = 1,maxn = 1;
	for (int i = 2;i <= n;i ++){
		if (t[i] == t[i-1])   cur ++;
		else maxn = max(maxn,cur),cur = 1;
	}
	maxn = max(maxn,cur);
	return maxn;
}

bool cmp(ll x,ll y){ return x > y; }

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0),cin.tie(0);
	
	cin >> n >> m;
	a.resize(n+1);
	for (int i = 1;i <= n;i ++)   cin >> a[i];
	
	sort(a.begin()+1,a.end(),cmp);
	ll ans = 0;
	for (int i = 1;i < n;i ++){
		
		vector <ll> b(n+1);
		for (int j = 1;j <= n;j ++)   b[j] = a[j];
		
		ll cur = m;
		for (int j = i+1;j <= n;j ++){
			
			if (cur-(b[i]-b[j]) >= 0){
				cur -= (b[i]-b[j]);
				b[j] = b[i];
			}
			if (cur-(b[i]-b[j]) < 0){
				b[j] += cur;
				cur = 0;
			}
		}
		ans = max(ans,search(b));
	}
	
	cout << ans;
	
	
	return 0;
}