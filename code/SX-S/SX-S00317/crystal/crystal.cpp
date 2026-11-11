#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;
typedef signed long long i64;
typedef unsigned long long u64;
#ifndef _DEBUG
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
#else
	#define fin cin
	#define fout cout
#endif

i64 nums[500005];
i64 chk(i64 n, i64 fla);
i64 jis(i64 n, i64 fla);

int main() {
	i64 n, m, res = 0;
	fin >> n >> m;
	for (i64 i = 0; i < n; i++) {
		fin >> nums[i];
	}
	sort(nums, nums + n);

	i64 le = -1000000000005, ri = 1000000000005, mid;
	while (le <= ri) {
		mid = (le + ri) >> 1;
		if (chk(n, mid) <= m) {
			res = mid;
			le = mid + 1;
		} else {
			ri = mid - 1;
		}
	}

	fout << jis(n, res);

#ifndef _DEBUG
	fin.close();
	fout.close();
#endif
	return 0;
}

i64 chk(i64 n, i64 fla) {
	i64 res = 0;
	for (i64 i = 0; i < n; i++) {
		if (nums[i] < fla) {
			res += fla - nums[i];
		}
	}

	return res;
}

i64 jis(i64 n, i64 fla) {
	i64 res = 0;
	for (i64 i = 0; i < n; i++) {
		if (nums[i] <= fla) {
			res ++;
		}
	}

	return res;
}
