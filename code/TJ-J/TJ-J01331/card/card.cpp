#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5,M=3e5+5;
int a[N],cnt[M],l[N],r[N]ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	cnt[a[i]]++;
    	if(cnt[i]==1)l[a[i]]=i;
    	else r[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(r[a[i]]!=0&&r[a[i]]!=i)
			{
				j=r[a[i]];
			}
			cnt[a[j]]++;
		}
	}
} 
