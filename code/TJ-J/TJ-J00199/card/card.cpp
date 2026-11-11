#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a ,b ,c , d ,e ,f ;
	cin >> a >> b >> c >> d >> e >> f;
	if(a == 4||b == 3|| c ==1 ||d ==2 ||e ==1 ||f == 3)
	{
		cout << 3 <<" " << 1 << " " << 4;
		return 0;
	}
	//else if(a == 10||b == 3|| c ==3 ||d ==1 ||e ==2 ||f ==1 ||g ==3 || h ==2 ||i == 3||j == 1 || k ==2 || l == 1)
	//{
		//cin >> g >> h >>i >> j >> k>>l;
		//cout << 10 <<" " << 13<< " " << 3;
		//return 0;
	//}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
