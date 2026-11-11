//SN-J00512
#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],ans[500005];
int nxt[500005]; // don't have -> 1e9
vector <int> same[300005];
bool f[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		same[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j+1<same[i].size();j++)
		{
			nxt[same[i][j]] = same[i][j+1];
		}
		nxt[same[i][int(same[i].size())-1]] = 1e9;
	}
	//for(int i=1;i<=n;i++)cout << nxt[i] << ' ';
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			//cout << j << ' ' << a[j] << ' ';
			if(!f[a[j]])ans[a[j]]++,f[a[j]] = 1;
			//cout << ans[a[j]] << endl;
			if(nxt[j] != 1e9)j = nxt[j];
		}
		//cout << endl;
		for(int k=1;k<=m;k++)f[k] = 0;
	}
	for(int i=1;i<=m;i++)cout << ans[i] <<' ';
	return 0;
}
