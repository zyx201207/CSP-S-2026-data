#include<bits/stdc++.h>
#define cs const
#define int long long
#define fore(x,m,n) for(int x=m;x<=n;x++)
using namespace std;

int n,m;
cs int N=5e5+5;
int a[N];

signed main()
{
#ifndef Debug
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#else
//	freopen("crystal4.in","r",stdin);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	cin>>n>>m;
	fore(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,cur=0,ans=1;
	fore(r,2,n)
	{
		cur+=(r-l)*(a[r]-a[r-1]);
		while(cur>m)
		{
			cur-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
-对于程序员来说，万圣节和圣诞节是同一天，为什么？
-因为Oct31==Dec25

fin:14:41
by:luckyWu

exp:100
*/