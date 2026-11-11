#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, ans;
int num[N];
char str[N];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i] >> str[i];
	}
	int key = 1, ans = 0, cnt = 0;
	for(int i = n; i >= 1; i--){
		if(i == key){
			break;
		}
		if(str[i] != str[key]){
			if(cnt + num[i] > num[key]){
				cnt = num[i] - (num[key] - cnt);
				key++;
			}
			str[i] = str[key];
			ans += cnt;
		}
		cnt += num[i];
	}
	cout << ans;
	return 0;
}
