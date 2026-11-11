#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt,cnt2;
int cnt3,cnt4;
char wei,wei2;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cnt >> cnt3 >> wei >> cnt2 >> cnt4 >> wei2;
	if(cnt==cnt2){
		cout << "1";
		if(cnt3==cnt4){
			cout << "1";
			if((wei<='C'&&wei2<='C')||wei>='D'&&wei2>='D'){
				cout << "1";
				if((wei=='C'&&wei2=='A')||(wei=='A'&&wei2=='C')){
					cout << "0";
				}else{
					cout << "1";
				}
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
