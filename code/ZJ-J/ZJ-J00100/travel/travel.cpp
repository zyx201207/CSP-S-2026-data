#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//travel
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	//判断是否在同一节车厢
	if(c1 == c2) cout << 1;
	else{
		cout << "0000";
		return 0;
	}
	
	//判断是否在同一排
	//cout << '\n';
	//cout << s1 << ' ' << s2 << '\n';
	if(s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
	else{
		cout << "000";
		return 0;
	}
	 
	//判断是否在同一侧
	int num1,num2;
	if(s1[2] == 'A') num1 = 1;
	if(s1[2] == 'B') num1 = 2;
	if(s1[2] == 'C') num1 = 3;
	if(s1[2] == 'D') num1 = 4;
	if(s1[2] == 'E') num1 = 5; 
	
	if(s2[2] == 'A') num2 = 1;
	if(s2[2] == 'B') num2 = 2;
	if(s2[2] == 'C') num2 = 3;
	if(s2[2] == 'D') num2 = 4;
	if(s2[2] == 'E') num2 = 5;
	
	bool flag1 = (num1 <= 3);
	bool flag2 = (num2 <= 3);
	if(flag1 == flag2) cout << 1;
	else{
		cout << "00";
		return 0;
	}
	
	//判断是否在相邻 
	if(abs(num1-num2) == 1) cout << 1;
	else cout << 0; 
} 
