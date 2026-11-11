#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string cyi;
	string syi;
	string cer;
	string ser;
	cin >> cyi >> syi >> cer >> ser;
	if(cyi == cer){
		cout << "1";
		if(syi[0] == ser[0]){
			if(syi[1] == ser[1]){
				cout << "1";
				if(syi[2] == 'D'){
					if(ser[2] == 'F'){
						cout << "1";
						if(syi[2]-ser[2] == 1 || ser[2]-syi[2] == 1){
							cout << "1";
						}
						else{
							cout << "0";
						}
					}
					else{
						cout << "00";
					}
				}
				if(ser[2] == 'D'){
					if(syi[2] == 'F'){
						cout << "1";
						if(syi[2]-ser[2] == 1 || ser[2]-syi[2] == 1){
							cout << "1";
						}
						else{
							cout << "0";
						}
					}
					else{
						cout << "00";
					}
				}
				else{
					cout << "1";
					if(syi[2]-ser[2] == 1 || ser[2]-syi[2] == 1){
						cout << "1";
					}
					else{
						cout << "0";
					}
				}
			}
			else{
				cout << "000";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000" << "\n";
		return 0;
	}
	return 0;
}

