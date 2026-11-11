#include <bits/stdc++.h>
using namespace std;
void megsort(int a[], int temp[], int l, int m, int r){
	int i = l, j = m+1, k = l;
	while(i<= m && j <= r){
		if(a[i] >= a[j]) temp[k++] = a[i++];
		else if(a[i] < a[j]) temp[k++] = a[j++];
	}
	while(i <= m) temp[k++] = a[i++];
	while(j <= r) temp[k++] = a[j++];
	for(int i = l; i <= r; i++) a[i] = temp[i];
}
void meg(int a[], int temp[], int l, int r){
	if(l >= r) return;
	int m = (l+r)/2;
	meg(a, temp, l, m);
	meg(a, temp, m+1, r);
	megsort(a, temp, l, m, r);
}
int main(){
	int n, m;
	cin >> n >> m;
	int a[10000], temp[10000], sum = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	meg(a, temp, 1, n);
	sum = a[1];
	for(int i = 2; i <= m; i++){
		sum  = (sum&a[i]);
	}
	cout << sum;
}
