#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(void){
	ifstream fin("subway.in", ios_base::in);
	ofstream fout("subway.out", ios_base::out);
	ll c, n, m, D, q;
	fin >> c >> n >> m >> D >> q;
	vector<ll> w(m + 1, 0);
	vector< vector<ll> > a, t;
	for(ll i=1;i<=m;i++) fin >> w[i];
	for(ll i=0;i<n;i++){
		ll k;
		fin >> k;
		vector<ll> ai(k, 0), ti(k, 0);
		for(ll j=0;j<k;j++) fin >> ai[j] >> ti[j];
		a.push_back(ai);
		t.push_back(ti);
	}
	vector<ll> d(n, -1);
	d[1] = 0;
	for(ll T=0;T<n;T++){
		for(ll i=0;i<n;i++){
			for(ll k=0;k<a[i].size();k++){
				for(ll j=0;j<n;j++){
					for(ll p=0;p<a[j].size();p++){
						if(a[i][k] == a[j][p]){
							if(d[i] == -1 && d[j] == -1) continue;
							if(d[i] == -1) {d[i] = d[j] + t[i][k] + t[j][p];continue;}
							if(d[j] == -1) {d[j] = d[i] + t[i][k] + t[j][p];continue;}
							if(d[i] > d[j] + t[i][k] + t[j][p]) {d[i] = d[j] + t[i][k] + t[j][p];continue;}
							if(d[j] > d[i] + t[i][k] + t[j][p]) {d[j] = d[i] + t[i][k] + t[j][p];continue;}
						}
					}
				}
			}
		}
	}
	while(q--){
		ll x, y, ans;
		fin >> x >> y;
		ans = w[x] + w[y];
		ll dm = 500000000;
		for(ll i=0;i<n;i++)
		for(ll j=0;j<a[i].size();j++)
			if(a[i][j] == y)
				for(ll k=0;k<n;k++)
				for(ll p=0;p<a[k].size();p++)
					if(a[k][p] == x){
						if(abs(d[i] - d[k]) > min(d[i], d[k])) dm = min(dm, d[i] + d[k] + t[i][j] + t[k][p]);
						else dm = min(dm, abs(d[i] - d[k]) + t[i][j] + t[k][p]);
					}
		fout << dm + ans << endl;
	}
	return 0;
}
