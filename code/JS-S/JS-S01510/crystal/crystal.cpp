#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[600001];
int tp,num,yu;
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	tp=1;num=1;ans=1;yu=m;
	for(int i=2;i<=n;i++)
	{
		yu-=num*(a[i]-a[i-1]);
		num++;
		while(yu<0)
		{
			yu+=a[i]-a[tp];
			num--;
			tp++;
		}
		if(num>ans) ans=num;
		//cout<<i<<' '<<num<<' '<<tp<<' '<<yu<<endl;
	}
	printf("%d\n",ans);
	return 0;
}
