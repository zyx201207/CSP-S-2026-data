#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string cs1, cs2, zv1, zv2;
	int m1, m2, n1, n2;
	cin>>cs1>>zv1>>cs2>>zv2;
	int zcs1, zcs2;
	if (cs1 == "02")
	{
		zcs1 = 2;
	}
	if (cs1 == "03")
	{
		zcs1 = 3;
	}
	if (cs1 == "04")
	{
		zcs1 = 4;
	}
	if (cs1 == "05")
	{
		zcs1 = 2;
	}
	if (cs1 == "06")
	{
		zcs1 = 6;
	}
	if (cs1 == "07")
	{
		zcs1 = 7;
	}
	if (cs1 == "08")
	{
		zcs1 = 8;
	}
	if (cs1 == "09")
	{
		zcs1 = 9;
	}
	if (cs1 == "10")
	{
		zcs1 = 10;
	}
	if (cs1 == "11")
	{
		zcs1 = 11;
	}
	if (cs1 == "12")
	{
		zcs1 = 12;
	}
	if (cs1 == "13")
	{
		zcs1 = 13;
	}
	if (cs1 == "14")
	{
		zcs1 = 14;
	}
	if (cs1 == "15")
	{
		zcs1 = 15;
	}
	if (cs1 == "17")
	{	
		zcs1 = 17;
	}
	if (cs2 == "02")
	{
		zcs2 = 2;
	}
	if (cs2 == "03")
	{
		zcs2 = 3;
	}
	if (cs2 == "04")
	{
		zcs2 = 4;
	}
	if (cs2 == "05")
	{
		zcs2 = 2;
	}
	if (cs2 == "06")
	{
		zcs2 = 6;
	}
	if (cs2 == "07")
	{
		zcs2 = 7;
	}
	if (cs2 == "08")
	{
		zcs2 = 8;
	}
	if (cs2 == "09")
	{
		zcs2 = 9;
	}
	if (cs2 == "10")
	{
		zcs2 = 10;
	}
	if (cs2 == "11")
	{
		zcs2 = 11;
	}
	if (cs2 == "12")
	{
		zcs2 = 12;
	}
	if (cs2 == "13")
	{
		zcs2 = 13;
	}
	if (cs2 == "14")
	{
		zcs2 = 14;
	}
	if (cs2 == "15")
	{
		zcs2 = 15;
	}
	if (cs2 == "17")
	{
		zcs2 = 17;
	}
	if (zcs1 != zcs2)
	{
		cout<<"0000";
		return 0;
	}
	if (zv1[0] == '0')
	{
		if (zv1[1] == '1')
		{
			m1 = 1;
		}
		if (zv1[1] == '2')
		{
			m1 = 2;
		}
		if (zv1[1] == '3')
		{
			m1 = 3;
		}
		if (zv1[1] == '4')
		{
			m1 = 4;
		}
		if (zv1[1] == '5')
		{
			m1 = 5;
		}
		if (zv1[1] == '6')
		{
			m1 = 6;
		}
		if (zv1[1] == '7')
		{
			m1 = 7;
		}
		if (zv1[1] == '8')
		{
			m1 = 8;
		}
		if (zv1[1] == '9')
		{
			m1 = 9;
		}
	}
	if (zv1[0] == '1')
	{
		if (zv1[1] == '0')
		{
			m1 = 10;
		}
		if (zv1[1] == '1')
		{
			m1 = 11;
		}
		if (zv1[1] == '2')
		{
			m1 = 12;
		}
		if (zv1[1] == '3')
		{
			m1 = 13;
		}
		if (zv1[1] == '4')
		{
			m1 = 14;
		}
		if (zv1[1] == '5')
		{
			m1 = 15;
		}
		if (zv1[1] == '6')
		{
			m1 = 16;
		}
		if (zv1[1] == '7')
		{
			m1 = 17;
		}
		if (zv1[1] == '8')
		{
			m1 = 18;
		}
	}
	if (zv2[0] == '0')
	{
		if (zv2[1] == '1')
		{
			m2 = 1;
		}
		if (zv2[1] == '2')
		{
			m2 = 2;
		}
		if (zv2[1] == '3')
		{
			m2 = 3;
		}
		if (zv2[1] == '4')
		{
			m2 = 4;
		}
		if (zv2[1] == '5')
		{
			m2 = 5;
		}
		if (zv2[1] == '6')
		{
			m2 = 6;
		}
		if (zv2[1] == '7')
		{
			m2 = 7;
		}
		if (zv2[1] == '8')
		{
			m2 = 8;
		}
		if (zv2[1] == '9')
		{
			m2 = 9;
		}
	}
	if (zv2[0] == '1')
	{
		if (zv2[1] == '0')
		{
			m2 = 10;
		}
		if (zv2[1] == '1')
		{
			m2 = 11;
		}
		if (zv2[1] == '2')
		{
			m2 = 12;
		}
		if (zv2[1] == '3')
		{
			m2 = 13;
		}
		if (zv2[1] == '4')
		{
			m2 = 14;
		}
		if (zv2[1] == '5')
		{
			m2 = 15;
		}
		if (zv2[1] == '6')
		{
			m2 = 16;
		}
		if (zv2[1] == '7')
		{
			m2 = 17;
		}
		if (zv2[1] == '8')
		{
			m2 = 18;
		}
	}
	if (m1 != m2)
	{
		cout<<"1000";
		return 0;
	}
	if (zv2[2] == 'A')
	{
		n2 = 1;
	}
	if (zv2[2] == 'B')
	{
		n2 = 2;
	}
	if (zv2[2] == 'C')
	{
		n2 = 3;
	}
	if (zv2[2] == 'D')
	{
		n2 = 6;
	}
	if (zv2[2] == 'F')
	{
		n2 = 7;
	}
	if (zv1[2] == 'A')
	{
		n1 = 1;
	}
	if (zv1[2] == 'B')
	{
		n1 = 2;
	}
	if (zv1[2] == 'C')
	{
		n1 = 3;
	}
	if (zv1[2] == 'D')
	{
		n1 = 6;
	}
	if (zv1[2] == 'F')
	{
		n1 = 7;
	}
	int li = n1 - n2;
	if (li > 0 && li >= 3)
	{
		cout<<"1100";
		return 0;
	}
	if (li < 0 && li <= -3)
	{
		cout<<"1100";
		return 0;
	}
	if (li > 0 && li != 1)
	{
		cout<<"1110";
		return 0;
	}
	if (li < 0 && li != -1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
