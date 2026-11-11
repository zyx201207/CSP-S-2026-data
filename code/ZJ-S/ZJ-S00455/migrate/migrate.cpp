#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char *p1,*p2,in[1000000];
#define gc() ((p1 == p2 && (p2 = (p1 = in) + fread(in,1,10,stdin),p1 == p2)) ? EOF : *p1++)

int read()
{
	int x = 0,f = 1;
	char c = gc();
	while (c < 48 || c > 57)
	{
		if (c == '-') f = -1;
		c = gc();
	}
	while (c >= 48 && c <= 57) x = x * 10 + c - 48,c = gc();
	return x * f;
}

long long readl()
{
	long long x = 0,f = 1;
	char c = gc();
	while (c < 48 || c > 57)
	{
		if (c == '-') f = -1;
		c = gc();
	}
	while (c >= 48 && c <= 57) x = x * 10 + c - 48,c = gc();
	return x * f;
}

void writel(long long x)
{
	if (x / 10) writel(x / 10);
	putchar(x % 10 + 48);
	return;
}

int C,T,n,nxtl[2000010],nxtr[2000010];
long long d,ans,a[2000010],fl[2000010],fr[2000010],gl[2000010],gr[2000010];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C = read(),T = read();
	while (T--)
	{
		n = read(),d = readl(),ans = 0;
		for (int i = 1;i <= n;i++) a[i] = readl(),fl[i] = fr[i] = gl[i] = gr[i] = 0;
		for (int i = 1,j = 1;i <= n;i++)
		{
			while (j < n && a[j + 1] - a[i] <= d) j++;
			nxtr[i] = j;
		}
		for (int i = n,j = n;i >= 1;i--)
		{
			while (j > 1 && a[i] - a[j - 1] <= d) j--;
			nxtl[i] = j;
		}
		for (int i = 1;i <= n;i++)
		{
			fl[i]++;
			if (nxtr[i] > i && nxtl[nxtr[i]] == i) fl[nxtr[i]] += fl[i];
			if (nxtr[i] > i + 1) gl[nxtr[i]]++;
		}
		for (int i = n;i >= 1;i--)
		{
			fr[i]++;
			if (nxtl[i] < i && nxtr[nxtl[i]] == i) fr[nxtl[i]] += fr[i];
			if (nxtl[i] < i - 1) gr[nxtl[i]]++;
		}
		for (int i = 2;i < n - 1;i++) ans += (nxtl[i] == nxtl[i + 1] ? fl[i + 1] - 1 : gl[i + 1]) * (nxtr[i] == nxtr[i + 1] ? fr[i] - 1 : gr[i]);
		writel(ans),putchar('\n');
	}
	return 0;
}
