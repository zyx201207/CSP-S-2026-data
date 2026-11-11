//and
#include<bits/stdc++.h>
#define ll long long
#define m(a,b) memset(a,b,sizeof(a))
using namespace std;
vector<int> a;
int n , m , dfsmax = INT_MIN;
const int M = 1e5*2+10;
bool vis[M];
int dfsans;
void dfs(int x){
	if (x == m+1){
		dfsmax = max(dfsmax,dfsans);
		return ;
	}
	for (int i = 1;i <= n;i++){
		if(vis[i]){
			vis[i] = false;
			if (x==1) {
				dfsans = a[i];
			}else {
				dfsans = (dfsans&a[i]);
			}
			dfs (x+1);
			
			vis[i] = true;
		}
	}
}
int main () {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int maxz = INT_MIN;
	a.resize(n+10);
	int cnt0 = 0;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		maxz = max(maxz,a[i]);
		if (a[i] == 0) cnt0++;
	}
	if (n-cnt0 < m){
		cout << 0;
		return 0;
	}
	if (m==1){
		cout << maxz;
	}else if (m == 2){
		int maxv = INT_MIN;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				maxv = max(maxv,(a[i]&a[j]));
			}
		}
		cout << maxv;
	}else if (m == n){
		int ans = a[1];
		for (int i = 2;i <= n;i++){
			ans = (ans&a[i]);
		}
		cout << ans;
	}else if (maxz < 4){
		int cnt[4] = {0,0,0,0};
		for (int i = 1;i <= n;i++){
			cnt[a[i]]++;
		}
		int sheng = 114514;
		if (cnt[3]>0&&cnt[1]>0){
			sheng = m - cnt[3] - cnt[1];
		} 
		if (sheng <= 0){
			cout << 3;
		}else if (sheng == 114514){
			if (cnt[3]>0){
				cout << 2;
			}else if (cnt[1]>0){
				cout << 0;
			}
		}
	}else if (m == 3){
		int ans = INT_MIN;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				for (int k = j+1;k <= n;k++){
					ans = max(ans,(a[i]&a[j]&a[k]));
				}
			} 
		}
		cout << ans;
	}else if(m == 4){
		int ans = INT_MIN;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				for (int k = j+1;k <= n;k++){
					for (int i1 = k+1;i1 <= n;i1++){
						ans = max(ans,(a[i]&a[j]&a[k]&a[i1]));
					}
				}
			} 
		}
		cout << ans;		
	}else if (m==5){
		int ans = INT_MIN;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				for (int k = j+1;k <= n;k++){
					for (int i1 = k+1;i1 <= n;i1++){
						for (int i2 = i1+1;i2<=n;i2++){
							ans = max(ans,(a[i]&a[j]&a[k]&a[i1]&a[i2]));
						}
					}
				}
			} 
		}
		cout << ans;			
	}else if (m==6){
		int ans = INT_MIN;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				for (int k = j+1;k <= n;k++){
					for (int i1 = k+1;i1 <= n;i1++){
						for (int i2 = i1+1;i2<=n;i2++){
							for (int i3 =i2+1;i3<=n;i3++){
								ans = max(ans,(a[i]&a[j]&a[k]&a[i1]&a[i2]&a[i3]));
							}
						}
					}
				}
			} 
		}
		cout << ans;		
	}else if (m==7){
		int ans = INT_MIN;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				for (int k = j+1;k <= n;k++){
					for (int i1 = k+1;i1 <= n;i1++){
						for (int i2 = i1+1;i2<=n;i2++){
							for (int i3 =i2+1;i3<=n;i3++){
								for (int i4 =i3+1;i4<=n;i4++){
									ans = max(ans,(a[i]&a[j]&a[k]&a[i1]&a[i2]&a[i3]&a[i4]));
								}
							}
						}
					}
				}
			} 
		}
		cout << ans;
	}else if(m==8){
		int ans = INT_MIN;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				for (int k = j+1;k <= n;k++){
					for (int i1 = k+1;i1 <= n;i1++){
						for (int i2 = i1+1;i2<=n;i2++){
							for (int i3 =i2+1;i3<=n;i3++){
								for (int i4 =i3+1;i4<=n;i4++){
									for (int i5=i4+1;i5<=n;i5++){
										ans = max(ans,(a[i]&a[j]&a[k]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]));
									}
								}
							}
						}
					}
				}
			} 
		}
		cout << ans;
	}else if (m==9){
		int ans = INT_MIN;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				for (int k = j+1;k <= n;k++){
					for (int i1 = k+1;i1 <= n;i1++){
						for (int i2 = i1+1;i2<=n;i2++){
							for (int i3 =i2+1;i3<=n;i3++){
								for (int i4 =i3+1;i4<=n;i4++){
									for (int i5=i4+1;i5<=n;i5++){
										for (int i6=i5+1;i6<=n;i6++){
											ans = max(ans,(a[i]&a[j]&a[k]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]));
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
	}else if (m==10){
		int ans = INT_MIN;
		for (int i = 1;i <= n;i++){
			for (int j = i+1;j <= n;j++){
				for (int k = j+1;k <= n;k++){
					for (int i1 = k+1;i1 <= n;i1++){
						for (int i2 = i1+1;i2<=n;i2++){
							for (int i3 =i2+1;i3<=n;i3++){
								for (int i4 =i3+1;i4<=n;i4++){
									for (int i5=i4+1;i5<=n;i5++){
										for (int i6=i5+1;i6<=n;i6++){
											for (int i7=i6+1;i7<=n;i7++){
												ans = max(ans,(a[i]&a[j]&a[k]&a[i1]&a[i2]&a[i3]&a[i4]&a[i5]&a[i6]&a[i7]));
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
	}else {
		m(vis,true);
		dfs(1);
		cout << dfsmax;
	}
	return 0;
} 
