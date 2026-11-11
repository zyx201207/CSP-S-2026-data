#include<bits/stdc++.h>

using namespace std;

const int MAXN = 500010;
int n;
long long m;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	priority_queue<long long> a;
	vector<long long> s;
	for(int i = 1; i <= n; ++i){
		int c;
		cin >> c;
		a.push(c);
	}
//	for(int i = 0; i <= 200; ++i)cout << x[i] << " ";
//	cout << endl;
	while(!a.empty()){
		int c = a.top();
		a.pop();
		s.push_back(c - a.top());
	}
//	for(int i = 0; i < n - 1; ++i){
//		cout << s[i] << " ";
//	}
//	cout << endl;
	int ans = 0, t = 0;
	int cnt = n - 2;
	while(t <= m){
		if(s[cnt] == 0){
			cnt--;
			ans++;
			continue;
		}
		t += (ans * s[cnt]) + s[cnt];
		int c = (ans * s[cnt] + s[cnt]);
		if(t <= m){
			ans++;
			cnt--;
			if(ans == n){
				cout << ans;
				return 0;
			}
		}
//		cout << ans << " " << t << " " << c << " " << cnt << endl;
	}
	ans++;
	cout << ans;
	return 0;
} 
