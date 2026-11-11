#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500010];
int cnt[300010];
int nxt[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int fnd[300010];
	for(int i = 1; i <= n; i++)
	nxt[fnd[a[i]]] = i, fnd[a[i]] = i;
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
		{
			cnt[a[j]]++;      
			while(nxt[j])	j = nxt[j];
		}
	for(int i = 1; i <= m; i++)
		cout << cnt[i] << " ";
}