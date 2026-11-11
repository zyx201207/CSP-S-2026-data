#include <bits/stdc++.h> 
using namespace std;
char op1,op2;
int c1,c2,s1,s2;
int ans1,ans2,ans3,ans4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> op1 >> c2 >> s2 >> op2;
	//Problem 1
	if(c1 == c2) ans1 = 1;
	else ans1 = 0;
	//Problem 2
	if(ans1 and s1 == s2) ans2 = 1;
	else ans2 = 0;
	//Problem 3
	if(ans2 and ((op1 < 'D' and op2 < 'D') or (op1 >= 'D' and op2 >= 'D'))){
		ans3 = 1;
	}
	else ans3 = 0;
	//Problem 4
	if(op1 == 'D') op1 = 'E';//d变e使得cd不相邻且df相邻 
	if(op2 == 'D') op2 = 'E';
	if(ans3 and abs(op1 - op2) == 1) ans4 = 1;
	else ans4 = 0;
	cout << ans1 << ans2 << ans3 << ans4;
	return 0;
}
