#include<bits/stdc++.h>
using namespace std;
int ort;
string cf, sf, cs, ss;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cf >> sf >> cs >> ss;
	if(cf == cs) {
		cout << "1";
		ort = 1;
	} else {
		cout << "0";
		ort = 0;
	}//车厢相同 
	if(ort == 1 && (sf[0] == ss [0] && sf[1] == ss[1])) {
		cout << "1";
	} else {
		cout << "0";
	}//车厢相同 && 同一排 
	if(ort == 1 && (sf[0] == ss [0] && sf[1] == ss[1]) && (((sf[2] >= 'A' && sf[2] <= 'C') && (ss[2] >= 'A' && ss[2] <= 'C'))||((sf[2] >= 'D' && sf[2] <= 'F') && (ss[2] >= 'D' && ss[2] <= 'F')))) {
		cout << "1";
	} else {
		cout << "0";
	}//车厢相同 && 同一排 && 过道同一侧  
	int f = 0;
	if (ort == 1 && (sf[0] == ss [0] && sf[1] == ss[1]) && (((sf[2] >= 'A' && sf[2] <= 'C') && (ss[2] >= 'A' && ss[2] <= 'C'))||((sf[2] >= 'D' && sf[2] <= 'F') && (ss[2] >= 'D' && ss[2] <= 'F')))){
		if (((sf[2] >= 'A' && sf[2] <= 'C') && (ss[2] >= 'A' && ss[2] <= 'C'))){
			if (abs(int(sf[2]-ss[2])) == 1){
				f = 1;
			}
		}
		if (((sf[2] >= 'D' && sf[2] <= 'F') && (ss[2] >= 'D' && ss[2] <= 'F'))){
			f = 1;
		}
	}
	if (f == 1){
		cout << "1";
	}else{
		cout << "0";
	}
	return 0;
}
