#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int pan = 1;
	cin >> a >> b >> c >> d;
	if(a == c && a != "01" && a != "16" && c != "01" && c != "16"){
		cout << "1";
		for(int i = 0;i < 2;i++){
			if(b[i] != d[i]){
				cout << "000";
				pan = 0;
				break;
			}
		}
		if(pan == 1){
			cout << "1";
			if('D' > b[2] && 'C' < d[2]){
				cout << "00";
			}else{
				cout << "1";
				if(d[2] - b[2] == 1 || d[2] - b[2] == -1){
					cout << "1";
				}else{
					cout << "0";
				}
			}
		}
	}else{
		cout << "0000";
	}
	return 0;
}
