#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],flag[N],cnt[N],stk[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int b=0,t=n;
	while(n--)
	{
		b++;
		int hh=b,tt=b,c=n;	
		memset(flag,0,sizeof flag);	
		memset(stk,0,sizeof stk);
		while(hh<=tt&&c!=0)
		{
			for(int i=hh;i<=b;i++)
			{
				stk[++tt]=a[i];
				c--;				
				if(flag[stk[tt]]!=0) 
				{
					tt==flag[stk[tt]];						
				}
				else flag[stk[tt]]=i;			
			}
		}
		for(int i=hh;i<=tt;i++)
		{
			cnt[stk[i]]++;
		} 
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}

