#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n,m,a[N],ans = -1;
ll d[N],f[N],s[N];
bool vis[N];
void dfs(int cur){
	if(cur == m + 1){
		memset(f,0,sizeof(f));
		ll fc = 0,l = a[d[1]];
		while(l){
			fc ++;
			f[fc] = l % 2;
			l /= 2;
		}
		for(ll i = 2;i <= m;i ++){
			memset(s,0,sizeof(s));
			ll sc = 0,k = a[d[i]];
			while(k){
				sc ++;
				s[sc] = k % 2;
				k /= 2;
			}
			fc = max(fc,sc);
			for(ll j = 1;j <= fc;j ++)
				if(f[j] == 1 && s[j] == 1) f[j] = 1;
				else f[j] = 0;
		}
		ll sum = 0,p = 1;
		for(ll i = 1;i <= fc;i ++) sum += f[i] * p,p *= 2;
		ans = max(ans,sum);
	}
	for(int i = d[cur - 1] + 1;i <= n;i ++)
		if(!vis[i]){
			vis[i] = true;
			d[cur] = i;
			dfs(cur + 1);
			vis[i] = false;
		}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;i ++) cin >> a[i];
	dfs(1);
	cout << ans;
	return 0;
}