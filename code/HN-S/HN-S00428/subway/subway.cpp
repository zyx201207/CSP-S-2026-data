#include<bits/stdc++.h>
using namespace std;
long long c , n , m , d , q , t[500001];
struct node{
	long long t;
	long long x;
}v[501];
int f(int x , int y){
	
}
int main(){
//	freopen("subway.in" , "r" , stdin);
//	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> t[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++) cin >> v[j].x >> v[j].t;
		
	}
	while(q--){
		int x , y;
		cin >> x >> y;
		cout << 0 << endl;
	}
	return 0;
} 
