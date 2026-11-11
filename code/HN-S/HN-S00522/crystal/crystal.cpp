#include <bits/stdc++.h>
using namespace std; 
long long m,n,a[500005],ans,tmp,tans=1,st=2,qianyishu;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
//		cin>>a[i];
//		cout<<a[i]<<endl;
	}
	
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		a[i]=a[i]-a[i-1];
	}
//	mint=a[1];
	for(int i=2;i<=n;i++)
	{
		if(tmp+a[i]*(i-st+1)<=m)
		{
			tmp=tmp+a[i]*(i-st+1);
			qianyishu+=a[i];
			tans++;
			if(ans<tans)
			{
				ans=tans;
//				mint=tmp;
			}
//			if(ans==tans&&mint>tmp)
//			{
//				mint=tmp;
//			} 
		}
		else
		{
			tmp=tmp-qianyishu+a[i]*(i-st+1);
			qianyishu-=a[st];
			qianyishu+=a[i];
			st++;
//			while(tmp>m)
//			{
//				if(st>=i) break;
//				tmp-=qianyishu;
//				qianyishu-=a[st];
//				st++;
//				tans--;
//			}
//			if(ans==tans&&mint>tmp)
//			{
//				mint=tmp;
//			} 
		}
//		printf("%lld %lld %lld %lld %lld\n",a[i],ans,tans,qianyishu,st);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
