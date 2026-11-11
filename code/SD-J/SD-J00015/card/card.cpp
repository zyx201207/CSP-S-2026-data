#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int N = 5e5+7,M = 3e5+7;
int n,m,a[N],b[N],ans[M],top;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int j=i;j<=n;j++)
		{
			int cnt = 0;
			for(int k=top-1;k>=0;k--)
			{
				cnt++;
				if(b[k]==a[j])
				{
					while(cnt--)top--;
					break;
				}
			}
			b[top++]=a[j];
		}
		for(int i=0;i<top;i++)
		{
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';

	fclose(stdin);
	fclose(stdout);
	return 0;
 }


