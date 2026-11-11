#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010];
int s[500010],l;
bool used[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= n;i++)
	{
		memset(used,0,sizeof(used));
		l = 0;
		for(int j = i;j <= n;j++)
			if(!used[a[j]])
				s[++l] = a[j],used[a[j]] = 1;
			else
			{
				while(s[l] != a[j])
					used[s[l]] = 0,l--;
			}
		for(int i = 1;i <= m;i++)
			if(used[i]) ans[i]++;
	}
	for(int i = 1;i <= m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
