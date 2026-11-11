#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;
int n, m, a[N], ans[N];
bool f[N], ff;

void Solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(!ff && a[i] < a[i - 1])
			ff = 1;
	}
	if(!ff){
		for(int i = 1; i <= n; i++)
			ans[a[i]] = i;
	}
	else{
		for(int i = 1; i <= n; i++){
			stack<int> st;
			memset(f, 0, sizeof(f));
			for(int j = i; j <= n; j++){
				if(f[a[j]]){
					while(st.top() != a[j]){
						f[st.top()] = 0;
						st.pop();
					}
					f[a[j]] = 0;
					st.pop();
				}
				st.push(a[j]);
				f[a[j]] = 1;
			}
			while(!st.empty()){
				ans[st.top()]++;
				st.pop();
			}
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << " ";
}

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	while(T--)
		Solve();
	return 0;
}

