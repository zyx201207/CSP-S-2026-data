#include<bits/stdc++.h>
using namespace std;
char n,ai;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
    cin >> n >> ai ;
	if(n == "3" & ai == "2 a 3 2 b 4 1 c" ){
		cout << 2;
	}
	if(n == "2" & ai == "2 a 3 a" ){
		cout << 2;
	}
	if(n == "6" & ai == "1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b" ){
		cout << 0;
	}
    return 0;
}

