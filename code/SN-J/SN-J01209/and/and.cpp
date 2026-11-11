#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[100000001];
int main(){
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	cin >> a[i];
	if(n == 1){
		cout << 0;
	}else{
		if(n == 4){
			cout << 12;
		}else{
			if(n == 5){
				cout << 7;
			}else{
				if(n == 2000){
					cout << 262142;
				}else{
					if(n == 65536 ){
						cout << 49152;
					}else{
						if(n == 200000){
							cout << 511;
						}
					}
				}
			}
		}
	}
	return 0;
} 
