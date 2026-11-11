#include <bits/stdc++.h>
using namespace std;
long long n,a,b,c[200010],ans = 0,mon = 0,k = 0;
int main (){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++){
		cin >> a >> b;
		for (int j = 1;j <= a;j++){
			c[++k] = b;
		}
	}
	for (int i = 1;i <= k / 2 + 1;i++){
		if (c[i] != c[k - i]){
			mon++;
		}
	}
	cout << mon;
	fclose (stdin);
	fclose (stdout);
}