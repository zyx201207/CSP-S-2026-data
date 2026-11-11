#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string r;
	for(int i = 1; i <= n; i++){
		long long x;
		string s;
		cin >> x >> s;
		for(int j = 0; j < x; j++){
			r += s;
		}
	}
	long long i = 0, j = r.size() - 1;
	long long cnt = 0;
	while(i <= j){
		if(r[i] != r[j]){
			cnt++;
		}
		i++;
		j--;
	}
	cout << cnt;
	return 0;
}
