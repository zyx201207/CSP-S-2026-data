#include <iostream>
using namespace std;
int main(){
	int m,n,a[10000];
	cin >> m >> n;
	for(int i = 0;i < m;i++){
		cin >> a[i];
	}
	for(int i = 0;i<m-1;i++){
		if(a[i]>=a[i+1]){
			a[i+1] = a[i];
		}
	}
	cout << a[m-n-1];
	return 0;
}
