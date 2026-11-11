#include <iostream>
using namespace std;

int main(){
	freopen("travel.in", "i", stdin);
	freopen("travel.out", "w", stdout);
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a==c){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(d-b==1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
