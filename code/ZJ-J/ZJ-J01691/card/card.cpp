#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int a[N], b[M];
int main(){
	freopen("card.in", "w", stdin);
	freopen("card.out", "r", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		string s = " ";
		for(int j = i;j <= n;j++){
			char c = a[j] + '0';
			if(s.find(c) != -1){
				s.erase(s.find(c), s.size());
			}
			s += c;
		}
		for(int i = 1;i <= s.size();i++){
			b[s[i] - '0']++;
		}
	}
	for(int i = 1;i <= k;i++){
		cout << b[i] << " ";
	}
	return 0;
}
