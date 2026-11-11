#include<bits/stdc++.h>
using namespace std;
int ok=1;
long long n,m,p[300005],ans[300005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	
	cin>>n>>m;
	for(int i=1;i<=n;++i) 
	{
		cin>>p[i];
		if(p[i]<p[i-1]) ok=0;
	}
	if(ok)
	{
		for(int i=1;i<=m;++i)
		{
			int l=1,r=n;
			while(l<=r)
			{
				int mid=(l+r+1)/2;
				if(p[mid]>i) r=mid-1;
				else if(p[mid]<i) l=mid+1;
				else 
				{
					while(p[mid+1]==i) mid++;
					ans[i]=mid;
					break;	
				}
			}
		} 
		for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			
		 	int a[300005]={0},cnt=0;
			for(int j=i;j<=n;++j) 
			{
				int ok1=0;
				for(long long k=1;k<=cnt;++k)
				{
					if(p[j]==a[k])
					{
						ok1=1;
						cnt=k;		
						break;
					}
				}
				if(!ok1)
				{
					cnt++;
					a[cnt]=p[j];
				}
			}
			for(int j=1;j<=cnt;++j) ans[a[j]]++;
		}
		for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	}
	return 0;
}

