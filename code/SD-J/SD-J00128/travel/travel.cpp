#include<bits/stdc++.h>
using namespace std;

int a1, b1, a2, b2;
char c1, c2;

int main(){
	//*
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	//*/
	scanf("%d %d%c %d %d%c", &a1, &b1, &c1, &a2, &b2, &c2);
	c1 += (c1 == 'D') ? 3 : 0;
	c2 += (c2 == 'D') ? 3 : 0;
	printf((a1 == a2) ? "1" : "0");
	printf((a1 == a2 && b1 == b2) ? "1" : "0");
	printf((a1 == a2 && b1 == b2 && abs(c1 - c2) <= 2) ? "1" : "0");
	printf((a1 == a2 && b1 == b2 && abs(c1 - c2) == 1) ? "1" : "0");
	return 0;
}


