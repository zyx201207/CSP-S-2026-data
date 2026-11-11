//王昭云  西安市曲江第一学校  SN-J01173
#include <iostream>

using namespace std;

int a1,a2;
char b1,b2;
string c1,s1,c2,s2; //c1,c2为车厢号，s1,s2为座位号，将s1,s2拆分为a1,b1与a2,b2，即排和列 

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	
	//将s1,s2转化为a1,a2与b1,b2 
	a1 = 10 * (s1[0] - '0') + s1[1] - '0';
	b1 = s1[2];
	a2 = 10 * (s2[0] - '0') + s2[1] - '0';
	b2 = s2[2];
	
	//第一次判断 
	if(c1 == c2) cout << 1;
	else cout << 0;
	
	//第二次判断 
	if(c1 == c2 && a1 == a2) cout << 1;
	else cout << 0;
	
	//第三次判断 
	if(c1 == c2 && a1 == a2 && ((b1 != 'D' && b2 != 'D' && b1 != 'F' && b2 != 'F') || (b1 == 'D' && b2 == 'F') || (b1 == 'F' && b2 == 'D'))) cout << 1;
	else cout << 0;
	
	//第四次判断 
	if(c1 == c2 && a1 == a2 && ((b1 == 'A' && b2 == 'B') || (b1 == 'B' && b2 == 'A') || (b1 == 'B' && b2 == 'C') || (b1 == 'C' && b2 == 'B') || (b1 == 'D' && b2 == 'F') || (b1 == 'F' && b2 == 'D'))) cout << 1;
	else cout << 0;
	
	return 0;
}

