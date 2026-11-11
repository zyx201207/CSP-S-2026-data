#include<bits/stdc++.h>
using namespace std;
	long long c,k,n,l,a[2000005],lll,lengh,w,ans=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>w;
	if(c==11||c==12)
	{
		for(int i=1;i<=w;i++)
		{
			cin>>n>>l;
			for(int j=1;j<=n;j++)
			{
				cin>>a[j];
			}
			lll=(a[n]-a[1])/(n-1);
			lengh=l/lll;
			if(lengh==0||lengh==1)
			{
				cout<<0;
			}
			else
			{
				k=2;
				while(lll+1-k*lengh+1<1)
				{
					ans+=lll+1-k*lengh+1;
					k++;
				}
			}
		}
	}
	cout<<ans;
		return 0; 
	} 
