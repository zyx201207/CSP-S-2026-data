#include<bits/stdc++.h>
using namespace std;
long long n , ans , len[200001] , sum , pos , res;
char a[200001];
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> len[i] >> a[i];
		sum += len[i];
	}
	if(n == 1){
		cout << 0;
		return 0;
	} 
	bool same = true;
	for(int i = 1;i < n;i++){
		if(a[i] != a[i + 1]){
			same = false;
			break;
		}
	}
	if(same){
		cout << 0;
		return 0;
	}
	pos = (n + 1) / 2; 
	long long l = 1 , r = sum;
	res = (sum + 1) / 2;
	bool outa = true;
	for(int i = 1;i <= pos;i++){
		if(l > res || r < res || l > r){
			break;
			outa = false;
		}
		if(a[i] != a[n + 1 - i]){
			ans += max(len[i] , len[n + 1 - i]);
			l += max(len[i] , len[n + 1 - i]);
			r -= max(len[i] , len[n + 1 - i]);
		}
		else{
			ans += max(len[i] , len[n + 1 - i]) - min(len[i] , len[n + 1 - i]);
			l += max(len[i] , len[n + 1 - i]) - min(len[i] , len[n + 1 - i]);
			r -= max(len[i] , len[n + 1 - i]) - min(len[i] , len[n + 1 - i]);
		}
	}
	if(!outa){
		if(a[pos] != a[n + 1 - pos]) ans -= max(len[pos] , len[n + 1 - pos]);
		else ans -= max(len[pos] , len[n + 1 - pos]) - min(len[pos] , len[n + 1 - pos]);
	}
	cout << ans;
	return 0; 
}
