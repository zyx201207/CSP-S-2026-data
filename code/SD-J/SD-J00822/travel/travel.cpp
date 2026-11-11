#include <bits/stdc++.h>
using namespace std;

string c1 , c2 , c3 , c4;

int main (){
	freopen ("travel.in" , "r" , stdin);
	freopen ("travel.out" , "w" , stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	int q1 , q2 , a1 , a2;
	q1 = c1[1] - '0';
	a1 = c3[1] - '0';
	a2 = c3[0] - '0';
	q2 = c1[0] - '0';
	if ((a1 != q1) || (a2 != q2)){
		cout << "0000";
		return 0;
	}//先看是不是在同一个车厢 question1
	cout << "1";
	q1 = c2[0] - '0';
	a1 = c4[0] - '0';
	q2 = c2[1] - '0';
	a2 = c4[1] - '0';
	if ((q1 != a1) || (q2 != a2)){
		cout << "000";
	}
	else{
		cout << "1";
		char jj , qq;
		jj = c2[2];
		qq = c4[2];
//		cout << "jj:"<<jj <<"qq:" << qq;
		if (((jj >= 'A' && jj <= 'C')&&(qq >= 'A' && qq <= 'C'))||((jj >= 'D' && jj <= 'F')&&(qq >= 'D' && qq <= 'F'))){
			cout << "1";
			if ((jj - qq == 1)||(jj - qq == -1)){
				cout << "1";
			}
			else {
				cout << "0";
			}
		}
		else {
			cout << "00";
		}
	}//判断是否在同一排 question2  with  question3
	
	return 0;
}

