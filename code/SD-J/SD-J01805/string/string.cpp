#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int a[200005];
char b[200005];
char e[20000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long l = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		for (int j = l;j <= l + a[i];j++){
			e[j] = b[i];
		}
		l += a[i];
	}
	for (int r = 1;r * 2 <= l;r++){
		if (e[r] != e[l - r + 1]){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
} 
