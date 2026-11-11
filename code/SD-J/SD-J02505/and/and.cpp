#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
struct ones{
	int num,sum;
}b[N];
string to_two(int x)
{
	string s;
	while (x)
	{
		s += x % 2 + '0';
		x /= 2;
	}
	reverse (s.begin(),s.end());
	return s;
}
bool cmp(ones q,ones p)
{
	if (q.num != p.num)
		return q.num > p.num;
	return q.sum > p.sum;		
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[N];
	string s;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		s = to_two(a[i]);
		b[i].sum = a[i];
		b[i].num = 0;
		for (int j = 0;j < s.length();j++)
			b[i].num += s[j]-'0';
	}	
	sort(b+1,b+n+1,cmp);
	int cnt = b[1].sum;
	for (int i = 2;i <= m;i++)
	{
		cnt &= b[i].sum;
	}
	cout << cnt;
	return 0;
} 
//10:41::我这个实力为什么T3能骗4个样例点？？？？？？？？？？？？？？？
//10:41::马化腾我会爆零吗 
