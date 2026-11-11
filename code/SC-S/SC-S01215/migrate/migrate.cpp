#include<bits/stdc++.h>
using namespace std;
long long n,d,c,t,ans=0;
long long x[2000005];
unsigned long long cha[2000005];
bool fl[2000005];//b必飞点 
int main()
{
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
		for(int j=1;j<=t;j++)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
				cha[i]=x[i]-x[i-1];
				
			}
			for(int i=3;i<=n;i++)
			if((cha[i]+cha[i-1])>d)
				{
					fl[i-1]=1;
				 } 
			
			//fl[1]=true;
			//fl[n]=true;
		for(int i=1;i<=n-3;i++)
			{
			//	if(fl[i]&&fl[i+3])
				if(fl[i+1]==0&&fl[i+2]==0&&cha[i+1]+cha[i+2]+cha[i+3]>d)
				{
					ans++;
				}
			}
			
			
			cout<<ans<<endl;
			ans=0;
			for(int i=1;i<=n;i++)
			{
				//if(fl[i])
				//cout<<i<<endl;
				fl[i]=0;
			}
			
		}
	return 0;
}