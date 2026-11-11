#include <bits/stdc++.h>
using namespace std;
//rp++
/*
luoguname：_Dustin_
*/
long long n,m;
long long a[500005];
long long b[500005],top = 0;
map < long long,long long>mp;
void play(long long lft,long long rgh)
{
	top = 0;
	for (int i = lft;i <= rgh;i++)
	{
		long long now = 0;
		for (int j = 1;j <= top;j++)
			if (a[i] == b[j]) now = j;
		if (now == 0)
			b[++top] = a[i];
		else
		{
			top = now - 1;
			b[++top] = a[i];
		}
	}
	for (int i = 1;i <= top;i++)
		mp[b[i]]++;
}
int main()
{
	freopen("card,in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		play(i,n);
	for (int i = 1;i <= m;i++)
		cout << mp[i] << " ";
	return 0;
}
