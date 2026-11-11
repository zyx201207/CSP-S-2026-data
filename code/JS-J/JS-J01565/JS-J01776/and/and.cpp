#include<bits/stdc++.h>
using namespace std;
struct S{
	int a,b;
};
bool cp(S x, S y)
{
	return x.b > y.b;
}
int use[35];
int main()
{
	freopen("and.cpp","r",stdin);
	freopen("and.cpp","w",stdout);
	int n, m;
	long long sum;
	S s[100005];
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> s[i].a;
		s[i].b = s[i].a;
	}
	sort(s + 1, s + 1 + n, cp);
	for(int i = 1;i <= n;i ++)
	{
		int x = s[i].a, len = 0, l = 0, re[35];
		while(x != 0)
		{
			len ++;
			if(x % 2 == 1)
			{
				l ++;
				re[l] = len;
			}
			x /= 2;
		}
		for(int j = 1;j <= l;j ++)
		{
			if(use[re[j]] != 2)
			use[re[j]] ++;
			else
			s[i].b -= pow(2, re[j] - 1);
		}
	}
    sort(s + 1,s + 1 + n, cp);
    sum = s[1].a;
    for(int i = 2;i <= m;i ++)
    {
		sum = sum & s[i].a;
	}
	cout << sum;
	//for(int i = 1;i <= m;i ++)
	return 0;
}
