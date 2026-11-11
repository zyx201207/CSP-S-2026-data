#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n,num[N],top;
char jc[N];
int jx[N];
char c[N];
long long sum;
bool check()
{
	for(int i = top;i >= 1;i --)
	{
		jx[top - i + 1] = num[i];
		jc[top - i + 1] = c[i];
	}
//	for(int i = 1;i <= top;i ++)
//	{
//		cout << jx[i] << " " << jc[i] << endl;
//	}
	for(int i = 1;i <= top;i ++)
	{
		if(jx[i] != num[i] || jc[i] != c[i]) return 0;
	}
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i ++)
	{
		cin >> num[i] >> c[i];
		sum += num[i];
		if(c[i] == c[i - 1])
		{
			num[i - 1] += num[i];
			num[i] = 0;
		}
		else
		{
			++ top;
		}
	}
	if(check()) cout << 0;
	else cout << 1LL * (sum / 2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
