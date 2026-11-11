#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ofstream fout("crystal.out");
    ifstream fin("crystal.in");
    ll n, m, ans = 1;
    fin >> n >> m;
    vector<int> crystals;
	crystals.reserve(n);
    for (int i = 0; i < n; i++) {
        int a;
        fin >> a;
        crystals.push_back(a);
    }
	sort(crystals.begin(), crystals.end());
	ll mused = 0;
	for (int i = 1; i < n; i++) {
		mused += ans*(crystals[i]-crystals[i-1])-(crystals[i]-crystals[i-ans]);
		if (mused+crystals[i]-crystals[i-ans] <= m) {
		    mused += crystals[i]-crystals[i-ans];
		    ans++;
	    }
	}
	fout << ans;
    return 0;
}

