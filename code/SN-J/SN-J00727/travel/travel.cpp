//毛彦腾 铜川市实验中学 SN-J00727 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel1","r",stdin);
	freopen("travel1","w",stdout);
	string a,b,c,d;
	cin >> a,b,c,d;
	if(a=="1"||a=="16"||c=="1"||c=="16")
	{
		cout << 0000;
	}
	if(a!=c)
	{
		cout << 0000;
	}
	else
	{
		cout << 1;
		if(b[0]==d[0]&b[1]==d[1])
		{
			cout << 111; 
		}
		else{
			cout <<000;
		}
	}
	return 0;
}
