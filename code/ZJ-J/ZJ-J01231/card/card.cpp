#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5;
const long long M = 3e5;
long long n,m,a[N+10],cnt[M+10],nex[N+10],last[N+10];
bool vis[M+10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)    cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		vector<long long> cards,p;
		for(int j = i; j <= n; j++)    cards.push_back(a[j]);
		for(int j = 0; j < (int)cards.size(); j++)    nex[j] = -1;
		for(int j = 1; j <= m; j++)    vis[j] = 0;
		for(int j = 1; j <= m; j++)    last[j] = -1;
		for(int j = 0; j < (int)cards.size(); j++)
		{
			if(last[cards[j]]!=-1)    nex[last[cards[j]]] = j;
			last[cards[j]] = j;
		}
		for(int j = 0; j < (int)cards.size(); j++)
		{
			p.push_back(cards[j]);
			if(nex[j]!=-1)    j = nex[j]-1;	
		}
		for(int j = 0; j < (int)p.size(); j++)
		{
			if(!vis[p[j]])
			{
				cnt[p[j]]++;
				vis[p[j]] = 1;
			}
		}
	}
	for(int i = 1; i <= m; i++)    cout << cnt[i] << " ";
	return 0;
}
