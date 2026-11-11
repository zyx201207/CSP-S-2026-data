#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200001];
	char c[200001];
	cin >> n;
	string S = "";
	int cnt = 0; 
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		cnt += a[i];
		for (int j = 1;j <= a[i];j++){
			S += c[i];
		}
	}
	int ans = 0;
	for (int i = 0;i <= cnt/2-1;i++){
		if (S[i] != S[cnt-i-1]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
