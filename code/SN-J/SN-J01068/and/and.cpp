#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m;
ll a[200005];
bool nm[200005][34];
ll ad[34], ans=0;
set<ll> no;

bool cmp(ll frt, ll nxt){
	return frt > nxt;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// input
	cin >> n >> m;
	for(ll i=1; i<=n; i++){
		cin >> a[i];
	}
	
	// solve
	sort(a + 1, a + n + 1, cmp);
	ll tmx=a[m];
	for(ll i=1; i<=n; i++){
		for(ll j=29; j>=0; j--){
			if((a[i] & (1 << j)) != 0){
				nm[i][j] = true;
				ad[j]++;
			}
		}
	}
	ll mxp=-1;
	for(ll i=29; i>=0; i--){
		if(ad[i] >= m){
			mxp = i;
			ans += 1 << i;
			for(ll j=n; j>0; j--){
				if(!nm[j][i]){
					no.insert(j);
					if((ll)no.size() == n - ad[i]){
						break;
					}
				}
			}
			break;
		}
	}
	if(mxp == -1){
		cout << 0 << '\n';
		return 0;
	}
	for(ll i=mxp-1; i>=0; i--){
		for(ll p : no){
			if(nm[p][i]){
				ad[i]--;
			}
		}
		if(ad[i] >= m){
			ans += 1 << i;
			for(ll j=n; j>0; j--){
				if(!nm[j][i]){
					no.insert(j);
					if((ll)no.size() == n - ad[i]){
						break;
					}
				}
			}
		}
	}
	
	// print
	cout << ans << '\n';
	
	// end
	return 0;
}
