#include <iostream> 
using namespace std;
int a[500005],b[500005],vis[300005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int pos=0;
		for(int j=i;j<=n;j++)
		{
			bool p=0;
			int s=0;
			for(int k=1;k<=pos;k++)
			{
				if(a[j]==b[k])
				{
					p=1;
					s=k;
					break;
				}
			}
			if(p==1)
			{
				for(int k=s;k<=pos;k++)
				{
					b[k]=0;
					pos--;
				}
			}
			pos++;
			b[pos]=a[j];
		}
		for(int j=1;j<=pos;j++)
		{
			vis[b[j]]=1;
			b[j]=0;
		}
		for(int j=1;j<=m;j++)
		{
			if(vis[j]==1)
			{
				ans[j]++;
			}
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
