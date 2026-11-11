#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m,a[N],tot[N],sa[N],aim=0;
//tot:总距离 
bool check(int lft,int rgt,int i)
{
	if((rgt-lft+1)*a[i]-(sa[rgt]-sa[lft-1])>=aim) return true;
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sa[i]=sa[i-1]+a[i];
	//前缀和一开始写到了排序前面，调了好久！！！！！！！！！ 
	tot[1]=0;
	int last=1,maxn=1;//上一个有多少相同
	for(int i=2;i<=n;i++)
	{
		aim=tot[i-1]+(a[i]-a[i-1])*last-m;
		if(aim<=0)
		{
			tot[i]=tot[i-1]+(a[i]-a[i-1])*last;
			last++;
			maxn=max(maxn,last);
			//cout<<i<<" "<<last<<endl;
			continue;
		}
		//(r-l+1)*a[n]-(a[lft]+...+a[rgt])>=m
		int lft=i-last;
		int l=lft,r=i-1,ans=0;
		while(l<=r)
		{
			int rgt=(l+r)/2;
			if(check(lft,rgt,i))
			{
				r=rgt-1;
				ans=rgt;
			}
			else l=rgt+1;
		}
		//ans+1~i
		tot[i]=tot[i-1]+(a[i]-a[i-1])*last-a[i]*(ans-lft+1)+(sa[ans]-sa[lft-1]);
		//if(i==4) cout<<tot[i-1]<<" "<<(a[i]-a[i-1])*last<<" "<<a[i]*(ans-l+1)<<" "<<sa[ans]-sa[l-1]<<endl;
		last=i-ans;
		//cout<<i<<" "<<last<<endl;
		maxn=max(maxn,last);
	}
	//cout<<a[315275]<<" "<<a[315276]<<endl;
	cout<<maxn<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
