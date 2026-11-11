 #include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	vector<int> cnt(m+1, 0);
	for(int t = 1;t <= n;t++){
		stack<int> z;
		vector<int> pd(m+1, false);
		for(int i = t;i <= n;i++){
			if(pd[a[i]]){
				while(!z.empty() && z.top() != a[i]){
					pd[z.top()] = false;
					z.pop();
				}
			}
			else{
				z.push(a[i]);
				pd[a[i]] = true;
			}
		}
		while(!z.empty()){
			cnt[z.top()]++;
			z.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i];
		if(i != m)cout << " ";
	}
	return 0;
}