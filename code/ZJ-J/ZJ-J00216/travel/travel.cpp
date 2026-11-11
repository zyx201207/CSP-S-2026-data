#include <bits/stdc++.h>
using namespace std;
string str1, str2, str3, str4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> str1 >> str2 >> str3 >> str4;
	if (str1 != str3){
		cout <<"0000";
		return 0;
	}cout << 1;
	int num1, num2;
	num1 = (str2[0] -'0')* 10 + (str2[1] -'0');
	num2 = (str4[0] -'0')* 10 + (str4[1] -'0');
	if (num1 != num2){
		cout << "000";
		return 0;
	}cout << 1;
	if ((str2[2] =='D' && str4[2] !='F') || (str2[2] =='F' && str4[2] !='D') || (str2[2] !='D' && str4[2] =='F') || (str2[2] !='F' && str4[2] =='D')){
		cout <<"00";
		return 0;
	}cout << 1;
	if (str2[2] == char(str4[2] + 1) || str2[2] == char(str4[2] - 1) || (str2[2] =='D' && str4[2] =='F') ||(str2[2] =='F' && str4[2] =='D')){
		cout << 1;
	}else{
		cout << 0;
	}return 0;
}