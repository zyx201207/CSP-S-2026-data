#include<bits/stdc++.h>
#define int long long
using namespace std;

int read_seat(string s){
	return (s[0] - '0') * 10 + (s[1] - '0');
}
//判断他的排数 

int read_hang(string s){
	return (s[2] - 'A' + 1);
}
//判断他的座位号（第几排第几个）：A为1 B位2 C位3 D位4 F位6

bool check1(int h1 , int h2){
	if (h1 >= 1 && h1 <= 3 && h2 >= 1 && h2 <= 3) return true;
	if ((h1 == 4 || h1 == 6) && (h2 == 4 || h2 == 6)) return true;
	return false; 
} 
//判断二人是否在同一侧 

bool check2(int h1 , int h2){
	if (h1 == 1) return h2 == 2;
	if (h1 == 2) return h2 == 1 || h2 == 3;
	if (h1 == 3) return h2 == 2;
	if (h1 == 4) return h2 == 6;
	if (h1 == 6) return h2 == 4;
} 

signed main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	//如果需要调试请注释
	//如果需要提交请删掉注释 
	
	int c1 , c2;
	string s1 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	int s1s = read_seat(s1) , s1h = read_hang(s1) , s2s = read_seat(s2) , s2h = read_hang(s2); 
	
	//第一层：判断是否为同一车厢 
	if (c1 == c2) cout << "1";
	else cout << "0";
	
	//第二层：判断是否为在同一节车厢的同一排
	if(c1 == c2 && s1s == s2s) cout << "1";
	else cout << "0";
	
	//第三层：判断是否为同一节车厢的同一排，且位于过道的同一侧 
	if(c1 == c2 && s1s == s2s && check1(s1h , s2h)) cout << "1";
	else cout << "0";
	
	//第四层：判断是否为在同一节车厢的同一排，位于过道的同一侧，且在该侧的
	//座位序列中相邻
	if(c1 == c2 && s1s == s2s && check1(s1h , s2h) && check2(s1h , s2h)) cout << "1";
	else cout << "0";
	
	//完结撒花 
	return 0;
}
