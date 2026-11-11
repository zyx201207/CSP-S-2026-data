#include<bits/stdc++.h>
using namespace std;
int c,T,a[2000005]; 
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--)
	{
		int n,d,ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		scanf("%d",a+i);
		for(int i=1;i<=n;i++)
		if(i%d==1 && i/d==1 && i>d)ans+=n-i;
		cout<<ans<<"\n";
	}
	return 0;
}
