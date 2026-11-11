#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1, s1, c2, s2;
bool chk1(){
	return c1 == c2;
}
bool chk2(){
	return s1.substr(0, 2) == s2.substr(0, 2);
}
bool chk3(){
	int f1, f2;
	if(s1[2] == 'D' || s1[2] == 'F')f1 = 1;
	else f1 = 0;
	if(s2[2] == 'D' || s2[2] == 'F')f2 = 1;
	else f2 = 0;
	return f1 == f2;
}
bool chk4(){
	char x1 = s1[2], x2 = s2[2];
	if(x2 == 'F')x2 == 'E';
	if(x1 > x2)swap(x1, x2);
	return (int)(x2 - x1) == 1 && x2 != 'D';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(chk1())cout << 1;
	else cout << 0;
	if(chk1() && chk2())cout << 1;
	else cout << 0;
	if(chk1() && chk2() && chk3())cout << 1;
	else cout << 0;
	if(chk1() && chk2() && chk3() && chk4())cout << 1;
	else cout << 0;
	return 0;
}
/*孩子别 怕荆棘 赤着脚
就能寻到 珍贵
你看这个天黑 焰火有多美
无需太多 的伤悲
人本都在 茂盛枯萎
但顽石和块垒 也开花蕊 */ 
