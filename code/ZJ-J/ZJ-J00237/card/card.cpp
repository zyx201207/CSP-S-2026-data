#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n,m,a[N],t[N],xt[N];
stack<ll> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;i ++) cin >> a[i];
	for(ll i = 1;i <= n;i ++){
		while(!s.empty()) s.pop();
		memset(xt,0,sizeof(xt));
		ll Max = 0;
		for(ll j = i;j <= n;j ++){
			if(j > i && a[j] == a[j - 1]) continue;
			Max = max(Max,a[j]);
			xt[a[j]] ++;
			while(xt[a[j]] > 1) xt[s.top()] --,s.pop();
			s.push(a[j]);
		}
		for(int j = 1;j <= Max;j ++) t[j] += xt[j];
	}
	for(int i = 1;i <= m;i ++) cout << t[i] << " ";
	return 0;
}