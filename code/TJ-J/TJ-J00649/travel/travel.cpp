#include <bits/stdc++.H>
using namespace std;

bool check(char a, char b) {
	int x = a-'A';
	int y = b-'A';
	if (x > y) {
		int t = x;
		x = y;
		y = t;
	}
	if ((0 <= x && x <= 2 && 0 <= y && y <= 2) || (3 <= x && x <= 4 && 3 <= y && y <= 4)) {
		return true;
	}
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	string p1, v1, p2, v2;
	cin >> p1 >> v1 >> p2 >> v2;
	
	string t1 = v1.substr(0, 2);
	string t2 = v2.substr(0, 2);
	char c1 = v1[2];
	char c2 = v2[2]; 
	
	// 判断是否在同一车厢 
	if (p1 == p2) cout << 1;
	else cout << 0;
	
	// 判断是否在同一节车厢的同一排 
	if (p1 == p2 && t1 == t2) cout << 1;
	else cout << 0; 
	
	// 判断是否在同一节车厢的同一排，且位于过道的同一侧
	if (p1 == p2 && t1 == t2 && check(c1, c2)) cout << 1;
	else cout << 0; 
	
	// 判断两张车票对应的座位是否相邻 
	if (p1 == p2 && t1 == t2 && check(c1, c2) && abs(c1 - c2) == 1) cout << 1;
	else cout << 0; 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
