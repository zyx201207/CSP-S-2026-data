#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[30005];
int s[30005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	cout << m << " " << 1;
	for(int i = 3;i < n;i++){
		cout << " " << a[i]+3;
	}
	return 0;
}
