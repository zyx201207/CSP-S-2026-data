#include<bits/stdc++.h>
using namespace std;
int main(){
	/*freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);*/
	int n, a[200010];
	char ch[200010];
	cin >> n;
	int chuan[900000010], cnt = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> ch[i];
		for(int j = cnt; j < a[i]; j++){
			chuan[j] = ch[1] - 'a'; 
		}
		if(i == 0){
			cnt += a[i] - 1;
		}else{
			cnt += a[i];
		}
	}
	int ans = 0;
	for(int i = 0; i <= cnt / 2; i++){
		if(chuan[i] != chuan[cnt - i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
