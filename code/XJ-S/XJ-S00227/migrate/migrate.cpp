#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int a[5005];
int danjing=0,shuangjing=0;
int flag;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=d;j++)
			{
				for(int k=i;k<=n;k++)
				{
					int b,c,e;
					b=a[i+1]-a[i];
					c=a[i+1]+j;
					e=k-3;
					if(b<=d&&c==a[k]&&e>0)
					{
						danjing++;
					}
					if(danjing==2)
					{
						shuangjing++;
						cout<<shuangjing<<endl;
						danjing=0;
						flag=1;
						break;
					}
					
				}
				if(flag==1)
				{
					break;
				}
			}
			if(flag==1)
	    	{
	    		flag=0;
				break;
			} 
		}
	}
	return 0;
} 
