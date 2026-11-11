#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N];
char b[N];
long long res = 0;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];	
	}
	int l = 1, r = n;
	while(l < r){
		int x = min(a[l], a[r]);
		a[l] -= x, a[r] -= x;
		if(b[l] != b[r])res = res + x;
		if(a[l] <= 0)l++;
		if(a[r] <= 0)r--;
	}
	cout << res;
	return 0;
}
