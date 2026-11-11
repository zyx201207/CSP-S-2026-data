#include <bits/stdc++.h>
using namespace std;
int main(){
//  freopen("travel.in","r",stdin);
//  freopen("traval.out","w".stdout);
    int a,b,m,n,x,y;
	cin >> a >> b >> m >> n >> x >> y;
	if(a == b){
		cout << 1;
	}else{
		cout << 0;
	}
	if(x == 'A'||x == 'B'||x == 'C'&&y == 'A'||y == 'B'||y =='C'){
		cout << 1;
	}else{
		cout << 0;
	}
	if(m - n == 1) {
		cout << 1;
	}else{
		cout << 0;
	}
	if (x - y == 1) {
		cout << 1;
	}else{
		cout << 0;
	}
    return 0;
} 
