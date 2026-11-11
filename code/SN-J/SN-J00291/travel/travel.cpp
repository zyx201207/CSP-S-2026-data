#include <bits/stdc++.h> 
using namespace std;
int main()
{
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == "02" && c2 == "02") //判断是否在同一个车厢 
	{
		cout << "1";//是则输出 1
		if (s1[1] == s2[1])//判断是否在同一个车厢的同一排 
		{
			cout << "1";//是则输出1 
			if((s1[2] == 'D')||(s1[2] == 'F')&&(s2[2] == 'D')||(s2[2] == 'F'))//判断是否位于同一侧 
			{
				cout << "1";//是则输出1 
			}
			else if((s1[2] == 'A')||(s1[2] == 'B')||(s1[2] == 'C')&&(s2[2] == 'A')||(s2[2] == 'B')||(s1[2] == 'C'))
			{
				cout << "1";
			} 
			else
			{
				cout << "00";
			}
		} 
		else
		{
			cout << "000";//不是则输出0 
		}
	}
	else
	{
	    cout << "0000";	//不是则输出0 
	} 
	return 0;
}
