#include <bits/stdc++.h>
using namespace std;
int n,m,x,cnt;
int a[500010],b[500010],c[500010],ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	x=1;
	while(x<=n)
	{
		cnt=0;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int i=x;i<=n;i++)
		{
			if(b[a[i]]&&b[a[i]]<=cnt) 
			{
				for(int j=b[a[i]]+1;j<=cnt;j++) b[c[j]]=0;
				cnt=b[a[i]];
			}
			else 
			{
			  	cnt++;
			  	c[cnt]=a[i];
			  	b[a[i]]=cnt;
			}
		}
		for(int i=1;i<=cnt;i++) ans[c[i]]++;
		x++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
