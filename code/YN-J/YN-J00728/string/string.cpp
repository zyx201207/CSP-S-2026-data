#include <bits/stdc++.h>
using namespace std;

int n;
struct stu {
	char shu, c;
} a[20001];
int sum;

//bool huiwen(){
//	for(int i=1;i<=n/2;i++){
//		for(int j=a.size)
//	}
//}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].shu >> a[i].c;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i].c - 97 == a[i + 1].c - 97)
			sum = 0;
	}
	cout << sum;


	fclose(stdin);
	fclose(stdout);
	return 0;
}