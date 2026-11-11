#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000005;
const int M = 5005;
//string s;
int n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	system("fc string.out string6.ans");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i] >> c[i];
	int ans=0;
	for(int l=1,r=n;l < r;){
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
	cout << ans << '\n';
	return 0;
}
/*
3
2 a
2 b
1 c
CCF Just_do_it.png
Flynewcat
尽管我无法证明它的对错，但我坚信它是对的！ 
*/
