#include <bits/stdc++.h>
using namespace std;
//#define DBGMODE false
//#define dbg if(DBGMODE)cout
const int N = 2e5 + 3;
struct part {
	char c;
	int len;
}parts[N];
vector <part> partsL, partsR;
int n;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
//	freopen ("C:\\Users\\Administrator\\Desktop\\down\\string\\string6.in", "r", stdin);
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	partsL.push_back({'!', 0});
	partsR.push_back({'!', 0});
	cin >> n;
	long long sumlen = 0;
	for (int i = 1; i <= n; ++ i) {
		cin >> parts[i].len >> parts[i].c;
		sumlen += parts[i].len;
	}
	long long tgtlen = (floor(1.0 * sumlen / 2)), sumL = 0, sumR = 0;
//	dbg << "tgtlen: " << tgtlen << '\n';
	
	int i = 1;
	while (true) {
		if (sumL + parts[i].len <= tgtlen) {
			sumL += parts[i].len;
			partsL.push_back(parts[i]);
		} else {
			if (sumL == tgtlen) {
				break;
			} else if (sumL < tgtlen) {
				int addlen = tgtlen - sumL;
				partsL.push_back({parts[i].c, addlen});
				sumL += addlen;
				break;
			}
		}
		++ i;
	}
//	if(DBGMODE) {
//		dbg << "L:\n";
//		for (auto x : partsL) {
//			dbg << x.c << ' ' << x.len << '\n';
//		}
//	}
	
	i = n;
	while (true) {
		if (sumR + parts[i].len <= tgtlen) {
			sumR += parts[i].len;
			partsR.push_back(parts[i]);
		} else {
			if (sumR == tgtlen) {
				break;
			} else if (sumR < tgtlen) {
				int addlen = tgtlen - sumR;
				partsR.push_back({parts[i].c, addlen});
				sumR += addlen;
				break;
			}
		}
		-- i;
	}
//	if(DBGMODE) {
//		dbg << "R:\n";
//		for (auto x : partsR) {
//			dbg << x.c << ' ' << x.len << '\n';
//		}
//	}
//	int cnt = 0;
	int iL = 0, iR = 0;
	long long diff = 0, endL = 0, endR = 0;
	while (endL != tgtlen || endR != tgtlen) {
//		++ cnt;
//		if (cnt > 20 && DBGMODE) break;
//		dbg << "================\n";
//		dbg << "current endL: " << endL << ", endR: " << endR << '\n';\
//		dbg << "current iL: " << iL << ", iR: " << iR << '\n'; 
		if (endL == endR) {
//			dbg << "---- case 1\n";
			++ iL, ++ iR;
			endL += partsL[iL].len, endR += partsR[iR].len;
//			dbg << "new: iL = " << iL << ", iR = " << iR << '\n';
//			dbg << "new part: lenL = " << partsL[iL].len << ", lenR = " << partsR[iR].len << '\n';
//			dbg << "cL: " << partsL[iL].c << ", cR: " << partsR[iR].c << '\n';
			if (partsL[iL].c != partsR[iR].c) {
//				dbg << "different c!\n";
				diff += min(partsL[iL].len, partsR[iR].len);
//				dbg << "diff added: " << min(partsL[iL].len, partsR[iR].len) << '\n';
			}
		} else if (endL < endR) {
//			dbg << "---- case 2\n";
			++ iL;
			int delta = endR - endL;
//			dbg << "delta: " << delta << '\n';
			endL += partsL[iL].len;
//			dbg << "new L element: " << partsL[iL].len << ", endL increased to: " << endL << '\n';
			if (partsL[iL].c != partsR[iR].c) {
				diff += min(partsL[iL].len, delta);
			}
		} else if (endR < endL) {
//			dbg << "---- case 3\n";
			++ iR;
			int delta = endL - endR;
//			dbg << "delta: " << delta << '\n';
			endR += partsR[iR].len;
//			dbg << "new R element: " << partsL[iR].len << ", endR increased to: " << endR << '\n';
			if (partsR[iR].c != partsL[iL].c) {
				diff += min(partsR[iR].len, delta);
			}
		}
	}
	
	cout << diff;
	return 0;
}
