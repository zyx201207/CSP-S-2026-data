#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i] >> c[i];
	}
	long long ans = 0;
	for(int i = 1, j = n; i <= j; ){
		if(a[i] == a[j]){
			if(c[i] == c[j]) i ++, j --;
			else{
				ans += a[i];
				i ++, j --;
			}
		}
		else if(a[i] > a[j]){
			if(c[i] == c[j]){
				a[i] -= a[j];
				j --;
			} 
			else{
				ans += a[j];
				a[i] -= a[j];
				j --;
			}
		}
		else{
			if(c[i] == c[j]){
				a[j] -= a[i];
				i ++;
			}
			else{
				ans += a[i];
				a[j] -= a[i];
				i ++;
			}
		}
	}
	cout << ans;
	return 0;
}