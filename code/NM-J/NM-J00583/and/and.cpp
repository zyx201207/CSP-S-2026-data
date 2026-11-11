#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], mmax;
int main(){
	freopen("and.in", "w", stdin);
	freopen("and.out", "w", stdout);
	cin  >>  n  >>  m;
	for(int i = 1;i <= n;++i){
		cin  >>  a[i];
		if(a[i] > mmax){
			mmax = a[i];
		}
	}
	if(m = 1){
		cout  <<  mmax;
		return 0;
	}
}
