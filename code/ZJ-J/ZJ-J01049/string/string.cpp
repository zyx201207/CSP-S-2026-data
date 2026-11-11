#include<bits/stdc++.h>
using namespace std;
string s;
char timp1,timp2,timp;
int n,sum;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	if(n == 1) {
		cin >> sum;
		cin >> timp;
		cout << 0;
		return 0;
	} else if(n == 2) {
		int a,b;
		cin >> a >> timp1;
		cin >> b >> timp2;
		if(timp1 == timp2) {
			cout << 0;
			return 0;
		}
		cout << min(a,b);
		return 0;
	}
	return 0;
}
