#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+10;
typedef long long ll;
const ll M = 1e12;
ll n,m,cnt = 0,maxl = M,maxm = 0,maxx = 0;
ll a[N];

map <ll,ll> ma;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	if(n == 1){
		cout << "1";
	}
	sort(a+1,a+n+1);
	for(int i = 0;i <= m;i++){
		for(int j = 1;j <= n;j++){
			ma[a[j] + i]++;
		}
	}
	map <ll,ll> :: iterator it;
	for(it = ma.begin();it != ma.end();it++){
		if(it -> second <= 1) continue;
		ll num = it -> first;
		ll i = 1,ans = 0;
		while(a[i] <= num){
			ans += num - a[i];
			i++;
		}
		if(ans <= m){
			maxx = max(maxx,it -> second);
		}
	}
	cout << maxx;
	return 0;
}
