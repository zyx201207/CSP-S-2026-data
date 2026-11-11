#include <bits/stdc++.h>
#define ll long long
using namespace std;

int x[2000005];

void dhy(){
	int n, d, ans = 0, dd = 0;
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> x[i];
		if(i <= 2){
			dd = abs(x[2] - x[1]);
		} else {
			if(dd != abs(x[i] - x[i-1])){
				dd = -1;
			}
		}
	}
	if(dd != -1){
		cout << "0\n";
		return;
	}
	if(n <= 9){
		for(int i=1;i<=n;i++){
			int cnt = 0;
			for(int j=i+1;j<=n;j++){
				if(x[j] - x[i] <= d){
					cnt++;
				}
			}
			if(cnt == 2){
				ans++;
			}
		}
		cout << ans-1 << "\n";
		return;
	}
	cout << "0\n";
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		dhy();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
============
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
********************
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int x[2000005];
set<int> cnt[2000005];

void dhy(){
	int n, d, ans = 0;
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	for(int i=1;i<n;i++){
		int Cnt = 0;
		for(int j=i+1;j<=n;j++){
			if(x[j] - x[i] <= d){
				if(cnt[j].size() && cnt[j].count(i)){
					Cnt++;
				} else {
					cnt[j].insert(i);
				}
			}
		}
		if(Cnt == 2){
			ans++;
		}
	}
	cout << ans << "\n";
}

int main(){
	//freopen("migrate.in", "r", stdin);
	//freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		dhy();
	}
	return 0;
}
*/ 
