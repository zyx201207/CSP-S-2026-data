#include<bits/stdc++.h>
using namespace std;
int t1, t2, t3, t4, a[11];
char c1, c2;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	scanf("%d %d%c %d %d%c", &t1, &t2, &c1, &t3, &t4, &c2);
	if(t1 == t3){
		a[1] = 1;
	}else{
		a[1] = 0;
	}
	if(t2 == t4 and a[1]){
		a[2] = 1;
	}else{
		a[2] = 0;
	}
	if(a[1] and a[2] and (c1 <= 'C' and c2 <= 'C' or c1 >= 'D' and c2 >= 'D')){
		a[3] = 1;
	}else{
		a[3] = 0;
	}
	if(a[1] and a[2] and a[3] and max(c1, c2) - min(c1, c2) == 1){
		a[4] = 1;
	}else{
		a[4] = 0;
	}
	cout << a[1] << a[2] << a[3] << a[4];
	return 0;
}
