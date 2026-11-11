#include <bits/stdc++.h>
using namespace std;
int n , a[200005] , m;
char b[200005];
long long s;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdin);
	cin >> n;
	for(int i = 0 ; i < n ; i++) cin >> a[i] >> b[i];
	int j = n / 2 - 1;
	for(int i = (n / 2 + n % 2) ; i < n ; i++)
	{
		if(b[i] != b[j]) s += max(a[i] , a[j]);
		j--;
	}
	cout << s;
	return 0;
}
