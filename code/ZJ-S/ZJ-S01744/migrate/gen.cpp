#include <bits/stdc++.h>
using namespace std;

#define FOR(x, y, z) for(int (x) = (y); (x) <= (z); (x)++)
#define ROF(x, y, z) for(int (x) = (y); (x) >= (z); (x)--)s
#define mp make_pair
#define pb push_back

mt19937 rng(0);

int GET(int l, int r){
	int p = rng() % (r - l + 1);
	return l + p;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T = 1000; cout << 0 << " " << T << '\n';

	while(T--){
		vector<int> vec;
		FOR(i, 1, 10) vec.pb(GET(-100, 100));
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		cout << vec.size() << " " << GET(1, 100) << "\n";
		for(auto i : vec) cout << i << " "; cout << "\n";
	}
	return 0;
}

/*
g++ gen.cpp -o gen
./gen > input
./migrate_bruteforce < input > ans
./migrate < input > output
*/