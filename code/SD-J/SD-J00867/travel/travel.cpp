#include <bits/stdc++.h>
using namespace std;
bool cnt[100];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string xrcx, xrzw, xxcx, xxzw;
	cin >> xrcx >> xrzw >> xxcx >> xxzw;
	if (xrcx == xxcx){
		cout << 1;
		string pai1 = xrzw.substr(0, 2);
		string pai2 = xxzw.substr(0, 2);
		if (pai1 == pai2){
			cout << 1;
			int xrzm = xrzw[2] - 'A';
			int xxzm = xxzw[2] - 'A';
			cnt[xrzm] = 1;
			cnt[xxzm] = 1;
			int cnt1 = 0;
			int cnt2 = 0;
			for (int i = 0; i < 3; i++){
				if (cnt[i]){
					cnt1++;
				}
			}
			if (cnt[3] == 1){
				cnt2++;
			}
			if (cnt['F' - 'A'] == 1){
				cnt2++;
			}
			if (cnt1 == 2){
				cout << 1;
				if ((cnt[0] == 1 && cnt[1] == 1) || (cnt[1] == 1 && cnt[2] == 1)){
					cout << 1;
				}else{
					cout << 0;
				}
			}else if(cnt2 == 2){
				cout << 11;
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	return 0;
}
