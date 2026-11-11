#include<bits/stdc++.h>
using namespace std;
int ans[5] = {0};
string a1, a2, b1, b2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> a1 >> a2 >> b1 >> b2;
	
	//问题 1：是否同车厢 
	if(!(a1 == b1)) {cout<<"0000";return 0;}    //不在同车厢 
	
	//问题 2：是否同一行 
	string a3, b3;
	char a4, b4;
	a3[0] = a2[0];
	a3[1] = a2[1];
	a4 = a2[2];
	b3[0] = b2[0];
	b3[1] = b2[1];
	b4 = b2[2];
	if(!(a3[0] == b3[0] && a3[1] == b3[1])) {cout<<"1000";return 0;}	//不在同一行 
	
	//问题 3：是否同一侧
	bool al = 0, bl = 0;
	if(a4 == 'A' || a4 == 'B' || a4 == 'C') al = 1;
	if(b4 == 'A' || b4 == 'B' || b4 == 'C') bl = 1;
	if(!(al == bl)) {cout<<"1100";return 0;}	//不在同一侧 
	
	//问题 4：是否相邻 
	if(a4 == 'A' && b4 == 'B' ||
	   a4 == 'B' && b4 == 'A' ||
	   a4 == 'B' && b4 == 'C' ||
	   a4 == 'C' && b4 == 'B' ||
	   a4 == 'D' && b4 == 'E' ||
	   a4 == 'E' && b4 == 'D') cout<<"1111";
	else cout<<"1110"; 
	
	return 0;
}
