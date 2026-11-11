#include <bits/stdc++.h>
using namespace std;
long long n , m , a[200005] , x, b[200005][200] , s = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n;i ++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i = n-1; i > n-3;i --){
		x=0;
		while(a[i] > 0){
			b[i][x]=a[i]%2;
			a[i]/=2;
			x++;
		}
	}
	for(int j = 0; j <= x;j ++){
		if(b[n-1][j]!=b[n-2][j]){
			b[n-1][j] = 0;
			cout << b[n][j] << ' ' << b[1][j] << endl;
		}
	}
		
	for(int i = 0; i < x;i ++){
		if(b[n-1][i] == 1){
			s += pow(2,i);
		}
	}
	cout << s;
	
	return 0;
} 
