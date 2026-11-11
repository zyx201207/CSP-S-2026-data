#include<bits/stdc++.h>
using namespace std;
int n, m;
int arr[500005];
int vis[300005];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= n; i++){
		stack<int> s;
		vector<int> v(m + 5, 0);
		for(int j = i; j <= n; j++){
			while(v[arr[j]] != 0){
				v[s.top()]--;
				s.pop();
			}
			s.push(arr[j]);
			v[arr[j]]++;
		}
		for(int i = 1; i <= m; i++){
			if(v[i])vis[i]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << vis[i] << ' ';
	}
	return 0;
}
