#include <bits/stdc++.h>
using namespace std;
const int N = 5 *1e5 + 5;
int a[N];
queue<int> q;
map<int , int > mp;
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	int n , m;
	cin>> n >>m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		q.push(a[i]);
	}
	
	


	return 0;
}

