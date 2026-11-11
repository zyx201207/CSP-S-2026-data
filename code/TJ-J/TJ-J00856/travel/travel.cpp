#include <bits/stdc++.h>
using namespace std;

char a[5], b[5];
int ex[4] = {0, 0, 0, 0}, ans[4] = {0, 0, 0, 0};
bool ab = false;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	for (int i = 0; i < 5; i++)  cin >> a[i];
	for (int i = 0; i < 5; i++)  cin >> b[i];
	
	//for (int i = 0; i < 5; i++)  cout << a[i] << " ";
	//for (int i = 0; i < 5; i++)  cout << b[i] << " ";
	
	for (int i = 0; i < 4; i++){
		if (a[i] == b[i])  ex[i] = 1;
	}
	
	/*for (int i = 0; i < 4; i++){
		cout << ex[i] << " ";
	}*/
	
	if ( ( int(a[4]) >= 65 && int(a[4] <= 67) ) && ( int(b[4]) >= 65 && int(b[4] <= 67) ) || ( int(a[4]) == 68 || int(a[4] == 70) ) && ( int(b[4]) == 68 || int(b[4] == 70) ) )  ab = true;
	
	if (ex[0] == 1 && ex[1] == 1)  ans[0] = 1;
	if (ans[0] && (ex[2] && ex[3]))  ans[1] = 1;
	if (ans[1] && ab)  ans[2] = 1;
	int _1 = abs( int(a[4])-int(b[4]) );
	if (ans[2] && (_1 == 1 || (_1 == 2 && ( int(a[4]) == 68 || int(a[4] == 70) ) && ( int(b[4]) == 68 || int(b[4] == 70) ) ) ) )  ans[3] = 1;
	
	for (int i = 0; i < 4; i++){
		cout << ans[i];
	}
	return 0;
}














































































// ACACACACACACACACACACACACACACACAC
// 0000000000000000
