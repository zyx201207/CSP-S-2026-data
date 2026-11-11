#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll l;
	char v;
}; 
node a[200005];
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	ll L = 0;
	int indx = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i].l >> a[i].v;
		L += a[i].l;
		for(int j = indx; j <= indx + a[i].l - 1; j++){
			c[j] = a[i].v;
		}
		indx += a[i].l;
	}
	ll ans = 0;
	for(int i = 1; i <= L / 2; i++){
		if(c[i] != c[L + 1 - i]) ans++;
	}
	cout << ans;
	return 0;
}

