#include <bits/stdc++.h>
using namespace std;
char b1,b2,b3;
char d1,d2,d3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a, c;
	cin >> a >> b1 >> b2 >> b3 >> c >> d1 >> d2 >> d3;
	if(a == c){
		cout << "1";
	}else{
		cout << "0";
	}
	if(b1 == d1 && b2 == d2&&a == c){
		cout << "1";
	}else{
		cout << "0";
	}
	if(a == c&&((b1 == d1&&a == c && b2 == d2 && b3 + 1 == d3 || b3 + 2 == d3 && d3 <= 'C')|| (b1 == d1 && b2 == d2&&d3 + 1 == b3 || d3 + 2 == b3 && b3 <= 'C'))){
		cout << "1";
	}else{
		cout << "0";
	}
	if(((b1 == d1 && b2 == d2 && b3 + 1 == d3 || b3 + 2 == d3 && d3 <= 'C')|| (b1 == d1 && b2 == d2&&d3 + 1 == b3 || d3 + 2 == b3 && b3 <= 'C')&&b3 == 'A' && d3 == 'B' || (b1 == d1 && b2 == d2 && b3 + 1 == d3 || b3 + 2 == d3 && d3 <= 'C')|| (b1 == d1 && b2 == d2&&d3 + 1 == b3 || d3 + 2 == b3 && b3 <= 'C')&&b3 == 'B' && d3 == 'A' ||(b1 == d1 && b2 == d2 && b3 + 1 == d3 || b3 + 2 == d3 && d3 <= 'C')|| (b1 == d1 && b2 == d2&&d3 + 1 == b3 || d3 + 2 == b3 && b3 <= 'C')&& b3 == 'B' && d3 == 'C' || b3 == 'C' && d3 == 'B'&&(b1 == d1 && b2 == d2 && b3 + 1 == d3 || b3 + 2 == d3 && d3 <= 'C')|| (b1 == d1 && b2 == d2&&d3 + 1 == b3 || d3 + 2 == b3 && b3 <= 'C'))&&a == c){
		cout << "1";
	}else if(((b1 == d1 && b2 == d2 && b3 + 1 == d3 || b3 + 2 == d3 && d3 <= 'C')|| (b1 == d1 && b2 == d2&&d3 + 1 == b3 || d3 + 2 == b3 && b3 <= 'C') &&b3 == 'D' && d3 == 'E' ||b3 == 'E' && d3 == 'D'&&(b1 == d1 && b2 == d2 && b3 + 1 == d3 || b3 + 2 == d3 && d3 <= 'C')|| (b1 == d1 && b2 == d2&&d3 + 1 == b3 || d3 + 2 == b3 && b3 <= 'C'))&&a == c){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
