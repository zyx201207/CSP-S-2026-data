#include <bits/stdc++.h>
using namespace std;
const int MX = 2e5;
struct node
{
	long long num;
	char ch;
}a[MX + 10];
long long cnt;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int calcright;
	cin >> calcright;
	for(int i = 1;i <= calcright;i++)
	{
		cin >> a[i].num >> a[i].ch;
	}
	int calcleft = 1;
	while(calcleft < calcright)
	{
		long long nowcalc = min(a[calcleft].num,a[calcright].num);
		if(a[calcleft].ch != a[calcright].ch)
		{
			cnt += nowcalc;
		}
		a[calcleft].num -= nowcalc;
		a[calcright].num -= nowcalc;
		if(a[calcleft].num <= 0)
		{
			calcleft++;
		}
		if(a[calcright].num <= 0)
		{
			calcright--;
		}
	}
	cout << cnt << '\n';
	return 0;
} 
