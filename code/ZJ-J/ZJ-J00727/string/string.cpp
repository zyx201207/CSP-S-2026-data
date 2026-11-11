#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ac[200005];
char c[200005],cc[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(long long i = 1;i <= n;i++) cin >> ac[i] >> cc[i];
	long long k = 1;
	a[1] = ac[1];
	c[1] = cc[1];
	for(long long i = 2;i <= n;i++){
		if(cc[i] == cc[i - 1]) a[k] += ac[i];
		else{
			k++;
			a[k] += ac[i];
			c[k] = cc[i];
		}
	}
	n = k;
	if(n == 2){
		char c1 = c[1];
		char c2 = c[2];
		if(c1 == c2){
			cout << 0;
			return 0;
		}
		else{
			cout << min(a[1],a[2]);
			return 0;
		}
	}
	char cur = c[1];
	bool flag = 1;
	for(long long i = 1;i <= n;i++)
		if(cur != c[i]) flag = 0;
	if(flag){
		cout << 0;
		return 0;
	}
	sort(a + 1,a + n + 1);
	cout << a[1];
	return 0;
}