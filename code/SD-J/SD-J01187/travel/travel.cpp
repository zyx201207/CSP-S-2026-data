#include<bits/stdc++.h>
using namespace std;

// 神秘CCF啊、、、、、、我只是想要一个省一有什么问题吗。。。。。。。。。 

using ll = long long;

ll c1;
ll c2;

string s1,s2;

ll s1_num, s2_num;  // 记录辆车座次行数
char s1_c, s2_c; 
 
 
bool check_same_b(char a, char b){
	//赋值其（ASCLL码 + 1） 
	ll ta = a - 'A' + 1;
	ll tb = b - 'A' + 1;
	
	//当都在左侧时（<= 3） 
	if(ta <= 3 && tb <= 3){
		return true;
	}
	
	//当都在右侧时 
	if(ta > 3 && tb > 3){
		return true;
	}
	
	//否 
	return false;
}

bool together(char a, char b){
	//赋值其（ASCLL码 + 1） 
	ll ta = a - 'A' + 1;
	ll tb = b - 'A' + 1;
	
	if(abs(ta - tb) == 1) return true;
	else return false;
}

int main(){
	//----
	ios::sync_with_stdio(false);
	cin.tie(0);
	//-----
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	//对应同一车厢 
	if(c1 == c2) {
		cout << "1";
	} else {  // 否则所有是0 
		cout << "0000\n";
		return 0;
	}
	
	//分解s1,s2;
	s1_num = (s1[0] - '0') * 10 + (s1[1] - '0');
	s2_num = (s2[0] - '0') * 10 + (s2[1] - '0');
	
	s1_c = s1[2];
	s2_c = s2[2];
	
	//判断是否同一行 
	
	if(s1_num == s2_num) {
		cout << "1"; 
	} else {
		cout << "000\n";
		return 0;
	}
	
	//判断是否同侧
	if(check_same_b(s1_c, s2_c)) {
		cout << "1";
	} else {
		cout << "00\n";
		return 0;
	}
	
	//判断是否相邻
	if(together(s1_c, s2_c)) {
		cout << "1";
	} else {
		cout << "0";
	}
	cout << "\n";	
	
	return 0;
} 
