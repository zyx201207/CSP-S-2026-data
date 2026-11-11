#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long a[200010];
char c[200010];
long long aa[200010];
char cc[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i){
        cin >> a[i] >> c[i];
	}
	for(int i = n, j = 1; i >= 1; --i, ++j){
        aa[j] = a[i];
        cc[j] = c[i];
	}
	for(int i = 1, j = 1; i <= n && j <= n;){
        if(a[i] > aa[j]){
            if(cc[j] != c[i]){
                ans += aa[j];
                a[i] -= aa[j];
                ++j;
            }else{
                a[i] -= aa[j];
                ++j;
            }
        }else if(a[i] == aa[i]){
            if(cc[j] != c[i]){
                ans += a[i];
                j++, i++;
            }else{
                j++, i++;
            }
        }else{
            if(cc[j] != c[i]){
                ans += a[i];
                aa[i] -= a[i];
                ++i;
            }else{
                aa[i] -= a[i];
                ++i;
            }
        }
	}
	long long ans1 = ans / 2;
	cout << ans1 << '\n';
    return 0;
}
