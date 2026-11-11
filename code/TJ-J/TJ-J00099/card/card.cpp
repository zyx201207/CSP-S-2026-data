#include<bits/stdc++.h>
using namespace std;
int n,m,c[500001],cnt[300001],last[300001];
void f(int in)
{
	for(int i = in;i <= n;i++)
	{
		if(last[c[i]]!=i) i=last[c[i]]-1;
		else cnt[c[i]]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	for(int i = n;i >= 1;i--)
	{
		last[c[i]]=max(last[c[i]],i);
	}
	for(int i = 1;i <= n;i++) f(i);
	for(int i = 1;i <= m;i++)
	{
		cout << cnt[i] << ' ';
	}
	return 0;
}
