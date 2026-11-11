#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    long long a, a1, b, b1;
    char c, d;
    cin >> a >> a1 >> c >> b >> b1 >> d;
    if(a == b){
		cout << 1;
	}else{
		cout << 0;
	}
	if(a1 == b1){
		cout << 1;
	}else{
		cout << 0;
	}
	if((c < 'D' && d < 'D') || (c > 'C' && d > 'C')){
		cout << 1;
	}else{
		cout << 0;
	}
	if(c + 1 == d || d + 1 == c){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}

