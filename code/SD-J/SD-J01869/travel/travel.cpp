#include <bits/stdc++.h>

using namespace std;

char a[5] , b[5] , c[5] , d[5];
int a1 = 0 , a2 = 0 , a3 = 0 , a4 = 0;
bool f1 = false , f2 = false;

int main() {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	scanf("%s%s%s%s" , a + 1 , b + 1 , c + 1 , d + 1);
	if(b[3] - 'A' < 3) f1 = true;
	if(d[3] - 'A' < 3) f2 = true;
	if(d[3] == 'F') d[3] = 'E';
	if(b[3] == 'F') b[3] = 'E';
	if(a[1] == c[1] && a[2] == c[2]) a1 = 1;
	if(a[1] == c[1] && a[2] == c[2] && b[1] == d[1] && b[2] == d[2]) a2 = 1;
	if(a[1] == c[1] && a[2] == c[2] && b[1] == d[1] && b[2] == d[2] && (f1 == f2)) a3 = 1;
	if(a3 && abs(b[3] - d[3]) == 1) a4 = 1;
	cout << a1 << a2 << a3 << a4;
	return 0;
} 
