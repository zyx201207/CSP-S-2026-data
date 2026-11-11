#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M = 2e5 + 5;

struct String 
{
	int st,e;
	char c;
	int a;
};
String s[M];
int n;

namespace ljn
{
	void solve()
	{
		freopen("string.in","r",stdin);
		freopen("string.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(0);
		
		cin >> n;
		int start = 1;
		for(int i = 1 ; i <= n ; i++)
		{
			int a;
			char c;
			cin >> a >> c;
			s[i].st = start;
			s[i].e = start + a - 1;
			start += a;
			s[i].c = c;
			s[i].a = a;
//			cout << s[i].st << " " << s[i].e << " " << s[i].c << " " << s[i].a << "\n";
		}
		int l = 1,r = start - 1;
		int lc = s[1].c,rc = s[n].c;
		int ls = 1,rs = n;
		int ans = 0;
		while(l <= r)
		{
//			printf("l = %lld,r = %lld,ans = %lld,ls = %lld,rs = %lld,lc = %c,rc = %c\n",l,r,ans,ls,rs,lc,rc);
			if(lc != rc)
			{
				if(r - s[rs].st + 1 > s[ls].e - l + 1)
				{
					int de = s[ls].e - l + 1;
//					printf("1,de = %lld\n",de);
					ans += de;
					l = s[ls].e + 1;
					ls++;
					lc = s[ls].c;
					r -= de;
				}
				else if(r - s[rs].st + 1 < s[ls].e - l + 1)
				{
//					cout << "1111111111" << '\n';
					int de = r - s[rs].st + 1;
//					printf("2,de = %lld\n",de);
					ans += de;
					r = s[rs].st - 1;
					rs--;
					rc = s[rs].c;
					l += de;
				}
				else if(r - s[rs].st == s[ls].e - l)
				{
					int de = r - s[rs].st + 1;
//					printf("3,de = %lld\n",de);
					ans += de;
					ls++;
					rs--;
					lc = s[ls].c;
					rc = s[rs].c;
					r -= de;
					l += de;
				}
			}
			else
			{
				if(r - s[rs].st + 1 > s[ls].e - l + 1)
				{
					int de = s[ls].e - l + 1;
//					printf("1,de = %lld\n",de);
					l = s[ls].e + 1;
					ls++;
					lc = s[ls].c;
					r -= de;
				}
				else if(r - s[rs].st + 1 < s[ls].e - l + 1)
				{
					int de = r - s[rs].st + 1;
//					printf("2,de = %lld\n",de);
					r = s[rs].st - 1;
					rs--;
					rc = s[rs].c;
					l += de;
				}
				else if(r - s[rs].st == s[ls].e - l)
				{
					int de = r - s[rs].st + 1;
//					printf("3,de = %lld\n",de);
					ls++;
					rs--;
					lc = s[ls].c;
					rc = s[rs].c;
					r -= de;
					l += de;
				}
			}
//			printf("l = %lld,r = %lld,ans = %lld\n",l,r,ans);
		}
		cout << ans << '\n';
		return ;
	}
}
signed main()
{
	ljn::solve();
	return 0;
}
/*
5
3 a
2 b
1 c
2 d
1 e
*/
