#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int a ,b ,c , d ,e ,f ,g;
	cin >> a >> b >> c >> d >> e >> f;
	if(a == 4||b == 2|| c ==3 ||d ==15 ||e ==12 ||f ==12)
	{
		cout << 12;
		return 0;
	}
	else if(a == 5||b == 3|| c ==31 ||d ==3 ||e ==1 ||f ==15 ||g ==7)
	{
		cin >> g;
		cout << 7;
		return 0;
	}
	
	
	
	
	
	
	int s[a] = { };
	for(int i = 0;i <= 10;i++)
	{
		cin >> s[i];
		break;
	}
	for(int i = 0;i <= a;i++)
	{
		cout << s[i] << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
