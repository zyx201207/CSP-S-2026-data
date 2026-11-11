#include <bits/stdc++.h> 
using namespace std;
int a[10000000] , maxn = -1e9 , ans = 0;
int s[2100]  , s1[2100] ;

int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	
	int n , m ;
	cin >> n >> m ;
	for(int i = 1; i <= n ;i++){
		cin >> a[i];

	}
	if(m == 1){
		for(int i = 1; i <= n; i++)
		{
			maxn = max(maxn , a[i]);
		}
		cout << maxn ;
	}
	
	return 0;
}
