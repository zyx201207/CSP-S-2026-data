#include<iostream>
#include<cstring>
using namespace std;
string s1,s2,s3,s4;
void judge(char x,char y)
{
	int a = x - 'A' + 1,b = y - 'A' + 1;
	if((a <= 3&&b > 3)||(a > 3&&b <= 3))
	{
		cout << "1100";
		return;
	}
	if(a + b == 4)
	{
		cout << "1110";
		return;
	}
	cout << "1111";
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1 != s3)
	{
		cout << "0000";
		return 0;
	}
	if(s2[1] != s4[1]||s2[0] != s4[0])
	{
		cout << "1000";
		return 0;
	}
	judge(s2[2],s4[2]);
}
