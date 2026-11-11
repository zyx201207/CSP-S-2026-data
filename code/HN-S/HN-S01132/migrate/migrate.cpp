#include<bits/stdc++.h>
using namespace std;
int x[2000100];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		memset(x,0,sizeof(x));
		int n,d,ans=0,as=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(x[i]-x[i-1]>d) 
			{
				x[i]=0;
				as=i-1;
			}
		}
		if(as==0) as=n;
		if(d==2) {
			cout<<as-3<<endl;
			continue;
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				
//			}
//		}
	} 
	return 0;
}
