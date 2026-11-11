#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string cr, sr, cx, sx;
ll num_cr, num_cx, num_sr, num_sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cr >> sr >> cx >> sx;
	for (ll i = 0; i < cr.size(); i++ ) num_cr = num_cr * 10 + (cr[i] - '0');
	for (ll i = 0; i < cx.size(); i++ ) num_cx = num_cx * 10 + (cx[i] - '0');
	if (num_cr != num_cx){
		cout << "0000\n";
		return 0;
	}
	for (ll i = 0; i < sr.size() - 1; i++ ) num_sr = num_sr * 10 + (sr[i] - '0');
	for (ll i = 0; i < sx.size() - 1; i++ ) num_sx = num_sx * 10 + (sx[i] - '0');
	if (num_sr != num_sx){
		cout << "1000\n";
		return 0;
	}
	ll n = sr.size() - 1;
	if (((sr[n] == 'A' || sr[n] == 'B' || sr[n] == 'C') && (sx[n] == 'D' || sx[n] == 'F')) || ((sx[n] == 'A' || sx[n] == 'B' || sx[n] == 'C') && (sr[n] == 'D' || sr[n] == 'F'))){
		cout << "1100\n";
		return 0;
	}
	if ((sr[n] == 'A' && sx[n] == 'B') || (sr[n] == 'B' && sx[n] == 'C') || (sr[n] == 'D' && sx[n] == 'F')){
		cout << "1111\n";
		return 0;
	}
	else if ((sx[n] == 'A' && sr[n] == 'B') || (sx[n] == 'B' && sr[n] == 'C') || (sx[n] == 'D' && sr[n] == 'F')){
		cout << "1111\n";
		return 0;
	}
	else{
		cout << "1110\n";
		return 0;
	}
	return 0;
}
