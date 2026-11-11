#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,r,mid,ans,n,m,a[500010],sum[500010];
int check(int len)
{
	int num=4e18;
	for(int i=1;i<=n-len+1;i++) num=min(num,a[i+len-1]*len-sum[i+len-1]+sum[i-1]);
	return num;
}
signed main()//100pts
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m,l=1,r=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)<=m) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
}
/*
这T1怎么这么简单？？？？
永恒的烈阳啊，
您是不灭之光，
是秩序的化身，
是契约之神，
是商业的守护者！ 
赞美太阳！
luogu id:caiboan;uid:忘了
100+52+56+20=228pts
一定要一等啊 
*/
