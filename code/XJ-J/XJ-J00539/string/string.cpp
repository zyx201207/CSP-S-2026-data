#include <bits/stdc++.h>
#include <string>
using namespace std;

int v;
long n , a ,cnt;
string b , m , u;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a >> b;
		for(int j = 1;j <= a;j++)m[j] = b[1];
	}
	cnt = m.size();
	for(int i = 1;i <= m.size();i++)
	{
		if(m[i] == m[cnt])v++;
		cnt--;
	}
	cout << v / 2;
	return 0;
}