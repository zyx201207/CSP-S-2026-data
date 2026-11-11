#include <iostream>
using namespace std ;
int a[10005] ;

int main(){
	freopen("and.in", "r", stdin) ;
	freopen("and.out", "w", stdout) ;
	long long n, m ;
	cin >> n >> m ;
	for(int i=0; i<n; i++){
		cin >> a[i] ;
	}
	long long b=0, max=0 ;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i!=j){
				b=a[i]&a[j] ;
				if(b>max){
					max = b ;
				}
			}
		}
	}
	cout << max ;
	return 0 ;
}
