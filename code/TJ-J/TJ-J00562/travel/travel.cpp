#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a!=c)
	{
		cout << "0000";
	}
	else
	{
		cout << 1;
		if(b[0]==d[0] && d[1]==b[1])
		{
			cout << 1;
			char nma=b[2],nmb=d[2];
			int ge=abs(nma-nmb);
			if(nma>='A' && nma<='C') 
			{
				if(nmb>='D' && nmb<='E') cout << "00";
				else 
				{
					cout << 1;
					if(ge==1)
					{
						cout << 1;
					}
					else cout << 0;
				}
			}
			else if(nma>='D' && nma<='E')
			{
				if(nmb>='A' && nmb<='C') cout << "00";
				else
				{
					cout << 1;
					if(ge==1)
					{
						cout << 1;
					}
					else cout << 0;
				}
			}
		}
		else cout << "000";
	}
	return 0;
}
