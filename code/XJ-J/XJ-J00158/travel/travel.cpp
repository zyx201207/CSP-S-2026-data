#include <bits/stdc++.h>
using namespace std;
int c[8];//c数组纯装饰，无意义，不然程序看的很怪 
string a,b,A,B;
char f[8];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a;
	cin >> A;
	cin >> b;
	cin >> B;
	if(a == b)
		c[1] = 1;
	else
	{
		cout << "0000";
		return 0;
	}
	if(A[0] == B[0] && A[1] == B[1])
		c[2] = 1;
	else
	{
		cout << "1000";
		return 0;
	}
	char C = A[2],D = B[2];
	if(C == 'D' && D == 'f' || D == 'D' && C == 'f')
	{
		cout << "1111";
	}	
	else if(C == 'A' && D == 'B' || C == 'B' && D== 'A')
	{
		cout << "1111";
	}
	else if(C == 'C' && D == 'A' || C == 'A' && D == 'C')
	{
		cout << "1110";
	}
	else
	{
		cout << "1100";
	}
}
