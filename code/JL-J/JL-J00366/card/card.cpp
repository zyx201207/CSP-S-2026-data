#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[100010];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= m ; i++) cout << n - i + 1 << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
