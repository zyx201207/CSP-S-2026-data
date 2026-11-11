#include <iostream>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

int c1, c2;
string s1, s2;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w",stdout);
	fast;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
		int num1 = 0, num2 = 0;
		for (int i = 0; i < 2; i++){
			num1 = num1 * 10 + s1[i] - '0';
			num2 = num2 * 10 + s2[i] - '0';
		}
		
		if (num1 == num2){
			cout << 1;
			char ch1 = s1[2], ch2 = s2[2];
			if (ch1 > ch2) swap(ch1, ch2);
			if (ch2 <= 'C' || ch1 >= 'D'){
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << "00";
		}
		
	} else {
		cout << "000";
	}
	
	char ch1 = s1[2], ch2 = s2[2];
//	cout << ch1 << " " << ch2 << '\n';
	if (ch1 > ch2){
		swap(ch1, ch2);
	}
	
	int num1 = 0, num2 = 0;
	for (int i = 0; i < 2; i++){
		num1 = num1 * 10 + s1[i] - '0';
		num2 = num2 * 10 + s2[i] - '0';
	}
	
	if ((ch2 <= 'C' || ch1 >= 'D') && char(ch1 + 1) == ch2 && c1 == c2 && num1 == num2){
		cout << 1;
	} else {
		cout << 0;
	}
	
	return 0;
}