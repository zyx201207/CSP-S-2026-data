#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],q[500005],top,ans[500005],ma;
bool v[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]]==0)
			{
				v[a[j]]=1;
				q[++top]=a[j];
			}
			else
			{
				while(1)
				{
					if(q[top]==a[j])
					{
						break;
					}
					v[q[top]]=0;
					top--;
					
				}
			}
		}
		while(top!=0)
		{
			ans[q[top]]++;
			v[q[top]]=0;
			top--;
		}//4 3 1 2 1 3
	}
	for(int i=1;i<=ma;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
