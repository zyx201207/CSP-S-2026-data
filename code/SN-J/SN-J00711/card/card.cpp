#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+7;
const int M = 3e5+7;
int n,m,a[N],f[M],ans[M];
vector<int> v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	for(int i = 1;i<=n;i++)
	{
		int v[N],top = 0;
		memset(f,0,sizeof f);
		for(int j = i;j<=n;j++)
		{
			if(!f[a[j]])
			{
				v[++top] = a[j];
				f[a[j]] = 1;
			}
			else
			{
				f[a[j]] = 0;
				while(v[top] != a[j]) top--;
			}
		}
		for(int k = 1;k<=top;k++)
		{
			ans[v[k]]++;
		}
	}
	for(int i = 1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
}
