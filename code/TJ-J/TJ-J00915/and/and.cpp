#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,c = 0,d = 1,e = -1;
	cin >> n >> m;
	for(int i = 1; i <= 30;i++){
		d *= 2;
	}
	d--;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
		b[i] = 0;
	}
	for(int i = 1; i <= n - m + 1;i++){
		c++;
		b[c] = a[c];
		for(int j = 2; j <= m;j++){
			b[c] = b[c] & a[j];
		}
	}
	for(int i = 1; i <= c;i++){
		if(b[i] >= e){
			e = b[i];
		}
	}
	cout << e;
	return 0;
}
