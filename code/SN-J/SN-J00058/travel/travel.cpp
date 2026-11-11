#include<bits/stdc++.h>
using namespace std;
string x1,x2,y1,y2;
int a[4] = {0};
int main(){
	freopen("travel.in","a",stdin);
	freopen("travel.out","b",stdout);
	cin >> x1 >> x2 >> y1 >> y2;
	if(x1 == y1){
		a[0] = 1;
	}
	if(x2[0] == y2[0] && x2[1] == y2[1]){
		a[1] = 1;
	}
	if((((x2[2] == 'A' || x2[2] == 'B' || x2[2] == 'C') && (y2[2] == 'A' || y2[2] == 'B' || y2[2] == 'C')) || (x2[2] == 'D' || x2[2] == 'F') && (y2[2] == 'F' || y2[2] == 'D'))){
		a[2] = 1;
	}
	if(x2[2] - 1 == y2[2] || x2[2] + 1 == y2[2]){
		a[3] = 1;
	}
	cout << a[0] << a[1] << a[2] << a[3];
	return 0;
}

/*
02 01A 02 01B

02 01C 02 01A
*/
