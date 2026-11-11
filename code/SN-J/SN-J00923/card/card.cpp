#include<bits/stdc++.h>
long long n,m,a[500005],ans[300005],cnt,c[300005];
using namespace std;
int main()
{
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		cnt=0;
		for(int ii=0;ii<n;ii++)
		{
			for(int iii=0;iii<cnt;iii++)
			{
				if(c[iii]==a[ii])
				{
					cnt=iii;
					break;
				}
			}
			c[cnt]=a[ii];
			cnt++;
		}
		for(int i=0;i<m;i++)
		{
			ans[c[i]]++;
		}
	}
	for(int i=0;i<m;i++)
	{
		cout<<ans[i]<<" ";
	}
    return 0; 
}
