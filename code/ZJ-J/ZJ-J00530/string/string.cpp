#include<bits/stdc++.h>
using namespace std;
int n;
struct asdf{
	long long int x;
	char y;
}a[200005];
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].x >> a[i].y;
	}
	asdf q = a[1] , m = a[n];
	long long int sum = 0;
	int i = 2;
	int j = n - 1;
	while(i - 1 < j + 1){
		long long int k = min(q.x , m.x);
		if(q.y != m.y){
			sum += k;
			q.x -= k;
			m.x -= k;
		}else{
			q.x -= k;
			m.x -= k;
		}
		if(q.x == 0){
			q = a[i];
			i++;
		}
		if(m.x == 0){
			m = a[j];
			j--;
		}
	}
	if(q.y != m.y){
		sum += min(q.x , m.x);
	}
	cout << sum;
	return 0;
}
/*
24474
*/
