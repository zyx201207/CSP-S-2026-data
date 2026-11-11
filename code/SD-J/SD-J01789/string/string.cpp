#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
char c[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int maxx = 0;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		char x;
		cin >> x;
		c[i] = x;
		maxx = max(maxx , a[i]);
	}
	if(n * maxx <= 1e8){
		string s = " ";
		int len = 0;
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= a[i];j ++){
				s += c[i];
				len ++;
			}
		}
		int ans = 0;
		for(int i = 1;i <= len + 1;i++){
			if(s[i] == s[len - i + 1]){
				continue;
			}
			ans ++;
		}
		cout << ans;
	}else{
		int ans = 0;
		for(int i = 1 , j = n;i <= j;){
			if(c[i] == c[j]){
				if(a[i] > a[j]){
					j --;
					a[i] -= a[j];
				}else if(a[i] < a[j]){
					i ++;
					a[j] -= a[i];
				}else{
					i ++ , j --;
				}
			}else{
				if(a[i] > a[j]){
					a[i] -= a[j];
					j --;
					ans += a[j];
				}else if(a[i] < a[j]){
					i ++;
					a[j] -= a[i];
					ans += a[i];
				}else{
					ans += a[i];
				    i ++ , j --;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
