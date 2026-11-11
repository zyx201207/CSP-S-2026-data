#include <iostream>
using namespace std;
int main(){
	int m,a[10000],n,aws=0;
	char d,b[10000];
	cin >> m;
	for(int i = 0,i<m,i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 0,i<m,i++){
		d += a[i] * b[i];
	}	
	n = len(d);
	if(n%2==1){
		for(int i = 0,i<m,i++){
			if(i!=n/2){
			d[i] != d[n-1-i];
			aws++;
			}
		}	
		
	}
	else{
		for(int i = 0,i<m,i++){
			d[i] != d[n-1-i];
			aws++;
	}
	cout << aws;
	return 0;
}
