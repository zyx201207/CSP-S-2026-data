#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 100;
long long T,a[N],ans = 0;
char c[N];
string s = "";
int main(){
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	cin >> T;
	for(int i = 1;i <= T;i++){
		cin >> a[i] >> c[i];
		if(c[i] == c[i - 1]){
			a[i - 1] += a[i];
			T--;
			i--;
		}
	}
	long long l = 1,r = T;
	while(l < r){
		if(c[l] == c[r]){
			if(a[l] > a[r]){
				a[l] -= a[r];
				r--;
			}
			else if(a[l] < a[r]){
				a[r] -= a[l];
				l++;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(a[l] > a[r]){
				a[l] -= a[r];
				ans += a[r];
				r--;
			}
			else if(a[l] < a[r]){
				a[r] -= a[l];
				ans += a[l];
				l++;
			}
			else{
				ans += a[l];
				l++;
				r--;
			}
		}
	}
	cout << ans;
	return 0;
}
