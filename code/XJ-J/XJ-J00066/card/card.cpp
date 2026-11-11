#include <bits/stdc++.h>
using namespace std;
const int maxn = 500005;
int n,m,a[maxn],ans[30005];
int que[maxn],head,tail;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		head = 1;
		tail = 1;
		memset(que,0,sizeof(que));
		for(int j = i;j<=n;j++)
		{
			for(int k = head;k<=tail;k++)
			{
					while(que[k] == a[j])
					{
						que[tail] = 0;
						tail--;
					}
				tail++;
				que[tail] = a[j];
			}
		}
		for(int j = head;j<=tail;j++)
		{
			ans[que[j]]++;
			//cout << que[j] << " ";
		}
		//cout << endl;
	}
	for(int i = 1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
