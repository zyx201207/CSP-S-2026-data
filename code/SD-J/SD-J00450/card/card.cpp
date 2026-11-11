//card
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n , m;
	cin >> n >> m;
	bool t = true;
	vector<int> a(n+10);
	vector<int> cnt(m+10,0);
	int l;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		if (a[i] < a[i-1]){
			t = false;
		}
	}
	if (t){
		for (int i = 1;i <= m;i++){
			cout << i << " ";
		}
		return 0;
	}
	for (int i = 1;i <= n;i++){
		vector<bool> b(m+10,false);
		stack<int> st;
		l = i;
		for (int j = l;j <= n;j++){
			if (b[a[j]]){
				while (true){
					if (st.top() == a[j])  break;
					b[st.top()] = false;
					st.pop();
				}
			}else {
				st.push(a[j]);
				b[a[j]] = true;
			}
		}
		while (!st.empty()){
			cnt[st.top()]++;
			st.pop();
		}
	}
	for (int i = 1;i <= m;i++) {
		cout << cnt[i] << " ";
	}
	return 0;
} 
