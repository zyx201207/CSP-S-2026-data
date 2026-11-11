#include<bits/stdc++.h>
using namespace std;
string m1, m2, m3, m4;
bool fl = 0;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>m1>>m2>>m3>>m4;
	if (m1==m3) {
		fl=1;
		cout<<"1";
	}
	if (fl == 1) {
		if (m2[1] == m4[1] && m2[2] == m4[2]) {
			fl = 0;
			cout << "1";
		} else {
			cout << "00";
		}
	} else {
		cout << "0000";
		return 0;
	}
	if (fl == 1) {
		if (m2[3] < 'D' && m4[3] < 'D' || m2[3] > 'C' && m4[3] > 'C') {
			cout << "1";
			fl=1;
		} else {
			cout << "0";
		}
	}else{
	cout<<"0";
	}
	if (fl == 1) {
		if (abs(m2[3] - m4[3])==1) {
			cout << "1";
		} else {
			cout << "0";
		}
	} else {
		cout << "0";
		cout<<"\n";
	}
	return 0;
}
