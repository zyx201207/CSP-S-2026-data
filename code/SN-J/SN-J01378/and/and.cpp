#include <iostream>
#include <stdio.h>
#include <cmath>
const int N = 1e6+10;
int n , m , a[N] , q[N] = {};;
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	int _max = 0;
	for (int i = 0 ; i < n ; i++){
		for (int j = 0 ; j < n ; j++){
			q[j] = 0;
		}
		for (int j = 1 ; j <= m ; j++){
			for (int k = i+1 ; k < n ; k++){
				if (q[k] == 0){
					_max = max(_max , int(a[i]&a[k]));	
					q[k] = 1;				
				}

			}
		}
	}
	cout << _max << endl;
	return 0;
}
