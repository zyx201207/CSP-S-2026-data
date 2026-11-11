#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin >> m >> n;
	int max1 = 0;
	for(int i = 0; i < m; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m-1; i++){
		for(int j = i+1; j < m; j++){
			max1 = max(max1,a[i] & a[j]);
		}
	}
	cout << max1;
	
	return 0;
}
