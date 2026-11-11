#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	int n;
	cin >> n;
	int a[200005];
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cout << a[i] << " "; 
	}
	return 0;
}
