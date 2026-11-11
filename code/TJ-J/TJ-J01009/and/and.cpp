#include <bits/stdc++.h>
using namespace std; 
int main(){
	
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);

	int n,m;
	cin >> n >> m;
	int a[1+n];
	for (int i = 0; i < n;i ++){
		cin >> a[i];
	}
	int max = 0,min,x,y,z;
	for (int i = 0;i < n;i++){
		for (int j = i+1;j < n;j ++){
			x = (a[i]&a[j]);
			if (x > max) max = x;
		}
	}
	cout << max;
	m -= 2;
	while (m != 0){
		for (int i = 0;i < n;i++){
			if ((a[i]&max) > max){
				max = (a[i]&max);
			}
		}
		m -= 1;
	}
	
	
	cout << max;
}
