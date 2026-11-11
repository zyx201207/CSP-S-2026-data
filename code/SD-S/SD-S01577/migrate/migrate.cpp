#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e6+5;
int a[N],b[N],tot;
int main()
{
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		tot=0;
		memset(b,0,sizeof(b));
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=n;i>=1;i--)
		{
			if(a[i]-a[i-1]>d)
			{
				a[i]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=0) b[++tot]=a[i];
		}
		if(tot%d==0) 
			cout<<tot/d/2<<endl;
		else 
			cout<<tot/d<<endl;
	}
//	fclose(stdin);
//	fclose(stdout);
}
