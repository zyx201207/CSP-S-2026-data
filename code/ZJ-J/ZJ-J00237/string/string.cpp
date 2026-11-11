#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll n,ans;
struct Node{
	ll a;
	char c;
}t[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i = 1;i <= n;i ++) cin >> t[i].a >> t[i].c;
	ll l = 1,r = n;
	while(l < r){
		if(t[l].c == t[r].c){
			if(t[l].a == t[r].a){
				l ++;
				r --;
			}
			else{
				if(t[l].a > t[r].a){
					t[l].a -= t[r].a;
					r --;
				}
				else{
					t[r].a -= t[l].a;
					l ++;
				}
			}
		}
		else{
			if(t[l].a == t[r].a){
				ans += t[l].a;
				l ++;
				r --;
			}
			else{
				if(t[l].a > t[r].a){
					t[l].a -= t[r].a;
					ans += t[r].a;
					r --;
				}
				else{
					t[r].a -= t[l].a;
					ans += t[l].a;
					l ++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}