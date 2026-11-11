#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char c;
ll n,x,len,cnt,l,r;
vector<pair<ll,char> > s;

pair<ll,char> get(ll got, bool lr) {
	ll index = 0;
	for (ll i = 0;i<n;i++) {
		if(index<=got && got<index+s[i].first) {
			if (lr) return {index+s[i].first-got,s[i].second};
			else return {got-index+1,s[i].second};
		}
		index += s[i].first;
	}
	return {0,'a'};
}

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	s.resize(n);
	for (ll i=0;i<n;i++) {
		cin >> x >> c;
		s[i].first = x;
		s[i].second = c;
		len += x;
    }
	
	l=0,r=len-1;
	while(l < r) {
		pair<ll,char> lcl = get(l,true),lcr = get(r,false);
		ll step = min(lcl.first,lcr.first);;
		if (lcl.second != lcr.second) cnt += step;
		l += step;
		r -= step;
	}
	cout << cnt << "\n";
	
	return 0;
}


