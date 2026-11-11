#include<bits/stdc++.h>
using namespace std;
#define int long long

int c1,c2;
string s1,s2;

namespace ljn
{
	pair<int,int> jx(string s)
	{
		int l = s[3] - 'A' + 1;
		int p;
		if(s[1] == '1')
		{
			p = (s[1] - '0') * 10;
			p += (s[2] - '0');
		}
		else
		{
			p = s[2] - '0';
		}
		if(l == 6) l = 5;
		return {l,p};
	}
	void solve()
	{
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(0);
		
		cin >> c1 >> s1 >> c2 >> s2;
		s1 = " " + s1;
		s2 = " " + s2;
		int flag[5];
		memset(flag,false,sizeof(flag));
		
		if(c1 == c2) flag[1] = true;
		else
		{
			for(int i = 1 ; i <= 4 ; i++)
			{
				cout << flag[i];
			}
			return ;
		} 
		
		pair<int,int> a,b;
		a = jx(s1);
		b = jx(s2);
//		cout << a.first << " " << a.second << " " << b.first << " " << b.second << " ";
		if(a.second == b.second) flag[2] = true;
		if(a.second == b.second && (a.first <= 3 && b.first <= 3) || (a.first > 3 && b.first > 3)) flag[3] = true;
		if((a.second == b.second && (a.first <= 3 && b.first <= 3) || (a.first > 3 && b.first > 3)) && abs(a.first - b.first) <= 1) flag[4] = true;
		
		for(int i = 1 ; i <= 4 ; i++)
		{
			cout << flag[i];
		}
		return ;
	}
}
signed main()
{
	ljn::solve();
	return 0;
}
