#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = -1e9;
long long a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			ans = max(ans, a[i] & 1);
		}
		cout << ans;
		return 0;
	} else if (m == 2) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, a[i] & a[j]);
			}
		}
		cout << ans;
		return 0;
	} else if (m == 3) {
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					ans = max(ans, a[i] & a[j] & a[k]);
				}
			}
		}
		cout << ans;
		return 0;
	} else if (m == 4) {
		for (int i = 0; i < n - 3; i++) {
			for (int j = i + 1; j < n - 2; j++) {
				for (int k = j + 1; k < n - 1; k++) {
					for (int l = k + 1; l < n; l++) {
						ans = max(ans, a[i] & a[j] & a[k] & a[l]);
					}
				}
			}
		}
		cout << ans;
		return 0;
	} else if (m == 5) {
		for (int i = 0; i < n - 4; i++) {
			for (int j = i + 1; j < n - 3; j++) {
				for (int k = j + 1; k < n - 2; k++) {
					for (int l = k + 1; l < n - 1; l++) {
						for (int o = l + 1; o < n; o++) {
							ans = max(ans, a[i] & a[j] & a[k] & a[l] & a[o]);
						}
					}
				}
			}
		}
		cout << ans;
		return 0;
	} else if (m == 6) {
		for (int i = 0; i < n - 5; i++) {
			for (int j = i + 1; j < n - 4; j++) {
				for (int k = j + 1; k < n - 3; k++) {
					for (int l = k + 1; l < n - 2; l++) {
						for (int o = l + 1; o < n - 1; o++) {
							for (int p = o + 1; p < n; p++) {
								ans = max(ans, a[i] & a[j] & a[k] & a[l] & a[o] & a[p]);
							}
						}
					}
				}
			}
		}
		cout << ans;
		return 0;
	} else if (m == 7) {
		for (int i = 0; i < n - 6; i++) {
			for (int j = i + 1; j < n - 5; j++) {
				for (int k = j + 1; k < n - 4; k++) {
					for (int l = k + 1; l < n - 3; l++) {
						for (int o = l + 1; o < n - 2; o++) {
							for (int p = o + 1; p < n - 1; p++) {
								for (int q = p + 1; q < n; q++) {
									ans = max(ans, a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q]);
								}
							}
						}
					}
				}
			}
		}
		cout << ans;
		return 0;
	} else if (m == 8) {
		for (int i = 0; i < n - 7; i++) {
			for (int j = i + 1; j < n - 6; j++) {
				for (int k = j + 1; k < n - 5; k++) {
					for (int l = k + 1; l < n - 4; l++) {
						for (int o = l + 1; o < n - 3; o++) {
							for (int p = o + 1; p < n - 2; p++) {
								for (int q = p + 1; q < n - 1; q++) {
									for (int r = q + 1; r < n; r++) {
										ans = max(ans, a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r]);
									}
								}
							}
						}
					}
				}
			}
		}
		cout << ans;
		return 0;
	} else if (m == 9) {
		for (int i = 0; i < n - 8; i++) {
			for (int j = i + 1; j < n - 7; j++) {
				for (int k = j + 1; k < n - 6; k++) {
					for (int l = k + 1; l < n - 5; l++) {
						for (int o = l + 1; o < n - 4; o++) {
							for (int p = o + 1; p < n - 3; p++) {
								for (int q = p + 1; q < n - 2; q++) {
									for (int r = q + 1; r < n - 1; r++) {
										for (int s = r + 1; s < n; s++) {
											ans = max(ans, a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << ans;
		return 0;
	} else if (m == 10) {
		for (int i = 0; i < n - 9; i++) {
			for (int j = i + 1; j < n - 8; j++) {
				for (int k = j + 1; k < n - 7; k++) {
					for (int l = k + 1; l < n - 6; l++) {
						for (int o = l + 1; o < n - 5; o++) {
							for (int p = o + 1; p < n - 4; p++) {
								for (int q = p + 1; q < n - 3; q++) {
									for (int r = q + 1; r < n - 2; r++) {
										for (int s = r + 1; s < n - 1; s++) {
											for (int t = s + 1; t < n; t++) {
												ans = max(ans, a[i] & a[j] & a[k] & a[l] & a[o] & a[p] & a[q] & a[r] & a[s] & a[t]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}
