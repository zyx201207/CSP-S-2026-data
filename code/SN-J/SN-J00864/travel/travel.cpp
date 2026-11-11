#include <iostream>
#include <cstring>
using namespace std;
string s1,c1,s2,c2,ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2){
		cout << "0000" << endl;
		return 0;
	}
	char j5 = s1[2],j6 = s2[2];
	for (int i = 0; i < 2; i++){
		if (s1[i] != s2[i]){
			cout << "1000" << endl;
			return 0;
		}
	}
	int y,h;
	if (j5 == 'A'){
		y = 1;
	}
	else if (j5 == 'B'){
		y = 2;
	}
	else if (j5 == 'C'){
		y = 3;
	}
	else if (j5 == 'D'){
		y = 4;
	}
	else{
		y = 5;
	}
	if (j6 == 'A'){
		h = 1;
	}
	else if (j6 == 'B'){
		h = 2;
	}
	else if (j6 == 'C'){
		h = 3;
	}
	else if (j6 == 'D'){
		h = 4;
	}
	else{
		h = 5;
	}
	if (!((y <= 3) & (h <= 3))){
		cout << "1100" << endl;
		return 0;
	}
	if (y - h == 1 || y - h == -1){
		cout << "1111" << endl;
	}
	else{
		cout << "1110" << endl;
	}
	return 0;
}
