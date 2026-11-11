#include <bits/stdc++.h>

using namespace std;

int n , m;
int a[500005] , lst[300005];

int main() {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) {
		scanf("%d" , &a[i]);
	}
	if(m == 1) {
		cout << n;
		return 0;
	}
	else if(m == 2) {
		int x = 0 , st = a[n];
		for(int i = 1 ; i <= n ; i++)
			if(a[i] != st) x++;
		printf("%d %d\n" , x , n);	
	}
	else {
		for(int i = 1 ; i <= n ; i++) lst[a[i]] = i;
		for(int i = 1 ; i <= m ; i++) printf("%d " , lst[i]);
	}
	return 0;
} 
