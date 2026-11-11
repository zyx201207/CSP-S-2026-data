#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],ans[300010],now[500010];
int main()
{
 	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		ll len=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=len;k++)
			{
				if(now[k]==a[j])
				{
					len=k-1;
					break;
				}
			}
			now[len+1]=a[j];
			len++;
//			for(int k=1;k<=len;k++)
//			{
//				cout<<now[k]<<" ";
//			}
//			cout<<endl;
		}
//		cout<<endl;
		for(int j=1;j<=len;j++)
		{
			ans[now[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

