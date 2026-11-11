#include<bits/stdc++.h>
using namespace std;
int a,b,c[500005],d,ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	d=0;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
		d+=c[i];
	}
	d+=b;
	d/=a;
	for(int i=1;i<=a;i++)
	{
		c[i]=abs(c[i]-d);
	}
	sort(c+1,c+a+1);
	for(int i=1;i<=a;i++)
	{
		if(b>=c[i])
		{
			b-=c[i];
			ans++;
		}
	}
	cout<<ans<<endl;
//	int l=1,r=b;
//	while(l<=r)
//	{
//		int mid=(l+r-1)/2;
//		ans=max(ans,check(mid));
//		
//	}//wogooglexiaokonglongliangcidouzai1122side
//erfenxiezhale
//shiftjianbunengyong
//"+" haideichupingjianpan
	return 0;
}
