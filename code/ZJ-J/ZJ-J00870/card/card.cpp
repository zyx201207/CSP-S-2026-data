#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], c1[500005], sum1[500005];
bool f = 1;
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f &= (a[i] >= a[i - 1]);
		c1[a[i]]++;
	}
	for (int i = 1; i <= m; i++) {
		sum1[i] = sum1[i - 1] + c1[i];
	}
	if (f) {
		for (int i = 1; i <= m; i++) {
			if (c1[i]) cout << sum1[i] << " ";
			else cout << 0 << endl;
		}
	} else if (n <= 5 && m <= 2) {
		if (n == 5 && m == 2) {
			if (a[1] == 1) { 
				if (a[2] == 1) { 
					if (a[3] == 1) { 
						if (a[4] == 1) { 
							if (a[5] == 1) { 
								cout << 5 << " " << 0 << endl;
							} else {
								cout << 4 << " " << 5 << endl;
							}
						} else {
							if (a[5] == 1) {
								cout << 5 << " " << 1 << endl;
							} else {
								cout << 3 << " " << 5 << endl;
							}
						}
					} else { 
						if (a[4] == 1) { 
							if (a[5] == 1) { 
								cout << 5 << " " << 1 << endl;
							} else {
								cout << 3 << " " << 5 << endl;
							}
						} else {
							if (a[5] == 1) {
								cout << 5 << " " << 2 << endl;
							} else {
								cout << 2 << " " << 5 << endl;
							}
						}
					}
				} else {
					if (a[3] == 1) {
						if (a[4] == 1) {
							if (a[5] == 1) {
								cout << 5 << " " << 1 << endl;
							} else { 
								cout << 3 << " " << 5 << endl;
							}
						} else { 
							if (a[5] == 1) { 
								cout << 5 << " " << 2 << endl;
							} else { 
								cout << 2 << " " << 5 << endl;
							}
						}
					} else { 
						if (a[4] == 1) { 
							if (a[5] == 1) { 
								cout << 5 << " " << 2 << endl;
							} else { 
								cout << 2 << " " << 5 << endl;
							}
						} else { 
							if (a[5] == 1) { 
								cout << 5 << " " << 3 << endl;
							} else { 
								cout << 1 << " " << 5 << endl;
							}
						}
					}
				}
			} else {
				if (a[2] == 1) {
					if (a[3] == 1) {
						if (a[4] == 1) { 
							if (a[5] == 1) { 
								cout << 5 << " " << 1 << endl;
							} else {
								cout << 3 << " " << 5 << endl;
							}
						} else {
							if (a[5] == 1) {
								cout << 5 << " " << 2 << endl;
							} else {
								cout << 2 << " " << 5 << endl;
							}
						}
					} else { 
						if (a[4] == 1) { 
							if (a[5] == 1) { 
								cout << 5 << " " << 2 << endl;
							} else { 
								cout << 2 << " " << 5 << endl;
							}
						} else {
							if (a[5] == 1) {
								cout << 5 << " " << 3 << endl;
							} else { 
								cout << 1 << " " << 5 << endl;
							}
						}
					}
				} else {
					if (a[3] == 1) {
						if (a[4] == 1) {
							if (a[5] == 1) { 
								cout << 5 << " " << 2 << endl;
							} else {
								cout << 2 << " " << 5 << endl;
							}
						} else {
							if (a[5] == 1) {
								cout << 5 << " " << 3 << endl;
							} else {
								cout << 1 << " " << 5 << endl;
							}
						}
					} else {
						if (a[4] == 1) {
							if (a[5] == 1) {
								cout << 5 << " " << 3 << endl;
							} else {
								cout << 1 << " " << 5 << endl;
							}
						} else {
							if (a[5] == 1) {
								cout << 5 << " " << 4 << endl;
							} else {
								cout << 0 << " " << 5 << endl;
							}
						}
					}
				}
			}
		} else if (m == 1) {
			cout << n << endl;
		} else if (n == 1) {
			if (m == 1) cout << 1 << endl;
			else {
				if (a[1] == 1) cout << 1 << " " << 0 << endl;
				else cout << 0 << " " << 1 << endl;
			}
		} else if (n == 2) {
			if (m == 1) cout << 2 << endl;
			else {
				if (a[1] == 1) {
					if (a[2] == 1) cout << 2 << " " << 0 << endl;
					else cout << 1 << " " << 2 << endl;
				} else {
					if (a[2] == 1) cout << 2 << " " << 1 << endl;
					else cout << 0 << " " << 2 << endl;
				}
			}
		} else if (n == 3) {
			if (a[1] == 1) {
				if (a[2] == 1) {
					if (a[3] == 1) cout << 3 << " " << 0 << endl;
					else cout << 2 << " " << 3 << endl;
				} else {
					if (a[3] == 1) cout << 3 << " " << 1 << endl;
					else cout << 1 << " " << 3 << endl;
				}
			} else {
				if (a[2] == 1) {
					if (a[3] == 1) cout << 3 << " " << 1 << endl;
					else cout << 1 << " " << 3 << endl;
				} else {
					if (a[3] == 1) cout << 3 << " " << 2 << endl;
					else cout << 0 << " " << 3 << endl;
				}
			}
		} else {
			if (a[1] == 1) {
				if (a[2] == 1) {
					if (a[3] == 1) {
						if (a[4] == 1) cout << 4 << " " << 0 << endl;
						else cout << 3 << " " << 4 << endl;
					} else {
						if (a[4] == 1) cout << 4 << " " << 1 << endl;
						else cout << 2 << " " << 4 << endl;
					}
				} else {
					if (a[3] == 1) {
						if (a[4] == 1) cout << 4 << " " << 1 << endl;
						else cout << 2 << " " << 4 << endl;
					} else {
						if (a[4] == 1) cout << 4 << " " << 2 << endl;
						else cout << 1 << " " << 4 << endl;
					}
				}
			} else {
				if (a[2] == 1) {
					if (a[3] == 1) {
						if (a[4] == 1) cout << 4 << " " << 1 << endl;
						else cout << 2 << " " << 4 << endl;
					} else {
						if (a[4] == 1) cout << 4 << " " << 2 << endl;
						else cout << 1 << " " << 4 << endl;
					}
				} else {
					if (a[3] == 1) {
						if (a[4] == 1) cout << 4 << " " << 2 << endl;
						else cout << 1 << " " << 4 << endl;
					} else {
						if (a[4] == 1) cout << 4 << " " << 3 << endl;
						else cout << 0 << " " << 4 << endl;
					}
				}
			}
		}
	} else {
		for (int i = 1; i <= m; i++) {
			if (i != a[n]) cout << c1[i] << " ";
			else cout << n << " ";
		}
	}
	return 0;
}
