#include<bits/stdc++.h>
using namespace std;
string c_1, c_2, s_1, s_2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int p = 0, q = 0;//左右 
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	//分割数字与字母 
	//cout << s_1[0]+s_1[1];
	//string w_1 = s_1[0]+s_1[1];
	//string w_2 = s_2[0]+s_2[1];
	char n_1 = s_1[2];
	char n_2 = s_2[2];
	//cout << n_1 << n_2;
	if(n_1 <= 'C') p = 1;
	else p = 2;
	if(n_2 <= 'C') q = 1;
	else q = 2;
	//cout << p << q;
	//问题1 
	if(c_1 == c_2 ){
		cout << 1;
		
	}
	else{
		cout << 0;
	}
	//问题2 
	//cout << s_1[0]+s_1[1];
	if(c_1 == c_2 && s_1[0]== s_2[0] && s_1[1] == s_2[1]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	//问题3 
	if(c_1 == c_2 && p == q && s_1[0]== s_2[0] && s_1[1] == s_2[1]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	//问题4
	if(n_1 == 'F') n_1 = 'E';
	if(n_2 == 'F') n_2 = 'E';
	if(c_1 == c_2 && p == q && s_1[0]== s_2[0] && s_1[1] == s_2[1]){
		if(n_1>n_2){
			if(n_1-n_2 == 1){
				cout << 1;
			}
			else{
				cout << 0;
			}
		}
		else{
			if(n_2-n_1 == 1){
				cout << 1;
			}
			else{
				cout << 0;
			}
		} 
	}
	else{
		cout << 0;
	}
	return 0;
}
