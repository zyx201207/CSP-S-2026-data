#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
bool _ = 1;
string ans = "";
pair<ll, char> grid[200005];
ll getcha(){
	ll aaa = 0, last = 0, lnow = 0, rnow = 0, rcnt = 0;
	ll l = 1, r = n + 1;
	while(l < r){//l++ -> r-=x aaa += xx
		lnow += grid[l].first;
		while(rnow < lnow){
			if(rnow > rcnt){
				if(rcnt + grid[r].first <= lnow){
					rcnt += grid[r].first;
					if(grid[r].second != grid[l].second){
						aaa += rcnt - rnow;
					}
					rnow = rcnt;
				}else{
					if(grid[r].second != grid[l].second){
						aaa += lnow - rnow;
					}
					rnow = lnow;
				}
			}
			else{
				r--;
				if(rnow + grid[r].first <= lnow){
					rcnt += grid[r].first;
					rnow += grid[r].first;
					if(grid[r].second != grid[l].second){
						aaa += grid[r].first;
					}
				} 
				else{
					if(grid[r].second != grid[l].second){
						aaa += lnow - rnow;
					}
					rnow = lnow;
				}
			}
			
		}
		l++;
	}
	return aaa;
}
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	char last = '0';
	ll last_ = 0;
	for(ll i = 1; i <= n; i++){
		cin >> grid[i].first >> grid[i].second;
		
		if(last != '0' && last != grid[i].second){
			_ = 0;
		}
		last = grid[i].second;
	}
	
	if(_){
		cout << 0 << endl;
		return 0;
	}
	if(n == 2){
		cout << min(grid[1].first, grid[2].first) << endl;
		return 0;
	}
	
	
	cout << getcha();
	return 0;
}
