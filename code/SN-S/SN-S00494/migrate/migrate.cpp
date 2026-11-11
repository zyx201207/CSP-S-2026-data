//SN-S00494+崔雅欣+西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,num,y[2000005],ci[200005],ju;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);	
	cin>>c>>t;
	for(int i=1;i<=n;i++) 
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++) cin>>y[j];
		for(int j=1;j<=n;j++) 
		{
			ci[j]=y[j]-y[j-1];
			if(y[j-1]>d)	n=j-1;
			ci[j]+=ci[j-1];
		}
		for(int j=2;j<=n;j++) 
		{
			for(int p=j+1;p<=n;p++)
			{
				ju=ci[p]-ci[j];
				if((ju+1)%d==0) num++;
			} 
		}
		cout<<num<<'/n';
	}	
	return 0;
}
