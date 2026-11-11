#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N];
int b[N];
int c[N];
int d[N];
map <int, int> mp;
stack <int> st;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.in", "w", stdout);
	int n, m, lenn = 1, len = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		for(int j = i; j <= n; j ++){
			if(mp[a[j]] > 0){
				while(!st.empty()){
					if(st.top() == a[j]){
						break;
					}
					mp[st.top()] --;
					st.pop(); 
				}
			}else{
				mp[a[j]] ++;
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			b[st.top()] ++;
			mp[st.top()] = 0;
			st.pop();
		}
		for(int j = 1; j <= m; j ++) mp[j] = 0;
	}
	for(int i = 1; i <= m; i ++) cout << b[i] << " ";
	return 0;
}
