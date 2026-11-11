#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005];
bool vis[35][200005];
int num[35];
int s;
bool ischeck[35][200005];
bool ch[35];
long long ans;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		long long tmp = a[i];
		int t = 0;
		while(tmp) {
			if((tmp & 1) == 1) {
				vis[t][i] = true;
				s = max(s,t);
				num[t]++;
				
			}
			tmp >>= 1;
			t++;
		}
	}
	/*
	for(int i = 1; i <= n; i++) {
		for(int j = 5; j >= 0; j--) {
			cout << vis[j][i] << " ";
		}
		cout << '\n';
	}
	cout << "num" << '\n';
	for(int i = 0; i <= 5; i++) {
		cout << num[i] << " ";
	}
	cout << '\n';
	cout << "s" << " " << s << '\n';
	*/
	int now = -1;
	while(s >= 0) {
		if(num[s] < m) {
			s--;
		}
		else {
			int cnt = 0;
			for(int i = 1; i <= n; i++) {
				if(now == -1){
					if(vis[s][i] == true) {
						ischeck[s][i] = true;
						cnt++;
					}
				}
				else {
					if(ischeck[now][i] == true){
						if(vis[s][i] == true) {
							ischeck[s][i] = true;
							cnt++; 
						}
					}
				}
			}
			if(cnt >= m) {
				now = s;
				ch[s] = true;
			}
			s--;
		}
	}
	/*
	for(int i = 0; i <= 32; i++) {
		cout <<  ch[i] << " ";
	}
	cout << '\n';
	*/
	long long res = 1;
	for(int i = 0; i <= 32; i++) {
		if(ch[i] == true) ans += res;
		res *= 2;
	}
	cout << ans;
	return 0;
}

