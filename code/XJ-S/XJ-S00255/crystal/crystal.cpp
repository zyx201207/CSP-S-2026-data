#include <iostream>
using namespace std;
int main(){
	int c,m,n=0,a[30];
	cin >> c >> m;
	for(int i = 0;i<c;i++){
		cin >> a[i];
	}
	for(int i = 0;i<c;i++){
		n+=a[i];
	}
	cout << (n+m)/c-1;
	return 0;
}
