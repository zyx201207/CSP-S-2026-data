//SN-J00835 把小煜 西安辅轮中学
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200010];
//int t[7000010][2];
//int num[7000010];
//int cnt;
//void insert(int x)
//{
//	int p=0;
//	num[0]++;
//	for(int i=1<<30;i;i>>=1)
//	{
//		if(x&i) 
//		{
//			if(!t[p][1]) t[p][1]=++cnt;
//			p=t[p][1];
//		}
//		else 
//		{
//			if(!t[p][0]) t[p][0]=++cnt;
//			p=t[p][0];
//		}
//		num[p]++;
//	}
//}
//void query()
//{
//	int p=0,s=0;
//	for(int i=1<<30;i;i>>=1)
//	{
//		if(t[p][1] && t[p][0])
//		{
//			s=i;
//			break;
//		}
//		if(t[p][1]) p=t[p][1];
//		else p=t[p][0];
//	}
//	for(int i=s;i;i>>=1);
//}
int ans;
void solve1()
{
	for(int sta=0;sta<(1<<n);sta++)
	{
		int cnt=0,sum=(1<<n)-1;
		for(int j=0;j<n;j++) if(sta&(1<<j)) cnt++;
		if(cnt!=m) continue;
		for(int j=0;j<n;j++) if(sta&(1<<j)) sum&=a[j+1];
		ans=max(ans,sum);
	}
	cout<<ans;
}
void solve2()
{
	if(m==1) for(int i=1;i<=n;i++) ans=max(ans,a[i]);
	if(m==2) for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
	if(m==n) 
	{
		ans=a[1];
		for(int i=1;i<=n;i++) ans&=a[i];
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
//		insert(a[i]);
	}
//	cout<<query();
	if(n<=20) solve1();
	else solve2();
	return 0;
}
