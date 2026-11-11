#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int c1, c2;
string s1, s2;
int l1, l2;
char o1, o2;
int check_same_side(char ch1, char ch2)
{
	if(ch1 == 'A'){
		return (ch2 == 'B' || ch2 == 'C');
	}
	else if(ch1 == 'B'){
		return (ch2 == 'A' || ch2 == 'C');
	}
	else if(ch1 == 'C'){
		return (ch2 == 'A' || ch2 == 'B');
	}
	else if(ch1 == 'D'){
		return (ch2 == 'F');
	}
	else {
		return (ch2 == 'D');
	}
	return 0;
}
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	l1 = (s1[0]-'0')*10 + (s1[1]-'0');
	l2 = (s2[0]-'0')*10 + (s2[1]-'0');
	o1 = s1[2];
	o2 = s2[2];
	
//	cout << c1 << " " << l1 << " " << o1 << "\n";
//	cout << c2 << " " << l2 << " " << o2 << "\n";
	
	if(c1 == c2){
		cout << 1;
		if(l1 == l2){
			cout << 1;
			if(check_same_side(o1, o2)){
				cout << 1;
				if((o1 == 'D' || o1 == 'F') || (o1 == 'A' && o2 == 'B') || (o1 == 'C' && o2 == 'B') || (o1 == 'B' && o2 == 'A') || (o1 == 'B' && o2 == 'C')){
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << 0 << 0;
			}
		} else {
			cout << 0 << 0 << 0;
		}
	} else {
		cout << 0 << 0 << 0 << 0;
	}
	return 0;
}

