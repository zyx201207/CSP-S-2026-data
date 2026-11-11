#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int n,m,o=0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i < n;i++){
		for (int j = i+1;j <= n;j++){
			if (a[i] | a[j] >= o){
				o = a[i] | a[j];
			}
		}
	}
	cout << o;
	return 0;
}