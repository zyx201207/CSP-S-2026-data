#include <bits/stdc++.h>
using namespace std;
int a,b;
char sa[5],sb[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a>>sa;
	cin >> b>>sb;
	if (a==b)
	{
		cout <<1;
	}
	else 
	{
		cout << "0000";
		return 0;
	}
	if (int(sa[0])==48&&int(sb[0])==48) // '0' -> int = 48
	{
		if (sa[1]==sb[1])
		{
			cout <<1;
		}
		else
		{
			cout << "000";
			return 0;
		}
	}
	else if (sa[0]==sb[0]&&sa[1]==sb[1])
	{
		cout << 1;
	}
	else 
	{
		cout << "000";
		return 0;
	}
	//C->int = 67
	if ((int(sa[2])<=67&&int(sb[2])<=67)||(int(sa[2])>67&&int(sb[2])>67))
	{
		cout << 1;
	}
	else 
	{
		cout <<"00";
		return 0;
	}
	if ( (int(sa[2])+1==int(sb[2])) || (int(sa[2])-1==int(sb[2])) )
	{
		cout <<1;
	}
	else
	{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
