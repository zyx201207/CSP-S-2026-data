#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,asize = 0;
vector<pair<ll,char>> p;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin >> n;
	char lastc = ' ';ll lastt = -1;
	for(int i = 0;i < n;i ++){
		ll a1;char c1;
		cin >> a1;cin >> c1;
		asize += a1;
		if(lastc!=c1){
			p.push_back({a1,c1});
			lastt++;
		}else{
			p[lastt].first += a1;
		}
		lastc = c1;
	}

	ll tp = 0,ans = 0;
	deque<pair<ll,char>> dq;

	if(asize&1){
		ll mid = (asize>>1)+1;
		for(auto u : p){
			ll x = u.first;char v = u.second;
			tp += x;
			if(tp < mid){
				dq.push_front({x,v});
			}else{
				if(tp-x+1<=mid){
					ll o = mid - (tp-x+1);
					if(o>0)dq.push_front({o,v});
					x = tp - mid;
				}
				while(x > 0){
					ll a1 = dq.front().first;char a2 = dq.front().second;
					if(a1 >= x){
						if(v != a2){
							ans += x;
						}
						dq.front().first -= x;
						if(dq.front().first == 0)dq.pop_front();
						break;
					}else{
						if(v != a2){
							ans += a1;
						}
						x -= dq.front().first;
						dq.pop_front();
					}
				}
			}
		}
	}else{
		ll mid = asize>>1;
		for(auto u : p){
			ll x = u.first;char v = u.second;
			tp += x;
			if(tp <= mid){
				dq.push_front({x,v});
			}else{
				if(tp-x+1<mid){
					ll o = mid - (tp-x+1);
					dq.push_front({o,v});
					x = tp - mid;
				}
				while(x > 0){
					ll a1 = dq.front().first;char a2 = dq.front().second;
					if(a1 >= x){
						if(v != a2){
							ans += x;
						}
						dq.front().first -= x;
						if(dq.front().first == 0)dq.pop_front();
						break;
					}else{
						if(v != a2){
							ans += a1;
						}
						x -= dq.front().first;
						dq.pop_front();
					}
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}