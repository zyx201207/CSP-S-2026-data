#include<iostream>
#include<cstring>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string qc1,qs1,qc2,qs2;
	cin >> qc1 >> qs1 >> qc2 >> qs2;
	if(qc1 == qc2) cout << "1";
	else cout << "0";
	
	string mj1,mj2;
	mj1 = qs1[0];
	mj1 += qs1[1];
	mj2 = qs2[0];
	mj2 += qs2[1];
	if(mj1 == mj2 && qc1 == qc2) cout << "1";
	else cout << "0";
	
	char kfc1,kfc2;
	kfc1 = qs1[2];
	kfc2 = qs2[2];
	if(kfc1 < kfc2) {
		char t = kfc1;
		kfc1 = kfc2;
		kfc2 = t;
	}
	if(kfc2 == 'A' && kfc1 == 'D') cout << "0";
	else if(kfc2 == 'A' && kfc1 == 'F') cout << "0";
	else if(kfc2 == 'B' && kfc1 == 'D') cout << "0";
	else if(kfc2 == 'B' && kfc1 == 'F') cout << "0";
	else if(kfc2 == 'C' && kfc1 == 'D') cout << "0";
	else if(kfc2 == 'C' && kfc1 == 'F') cout << "0";
	else if(mj1 == mj2 && qc1 == qc2) cout << "1";
	else cout << "0";
	
	if(mj1 == mj2 && qc1 == qc2 && kfc1 - kfc2 == 1 && kfc1 != 'D') cout << "1";
	else cout << "0";
	return 0;
}
