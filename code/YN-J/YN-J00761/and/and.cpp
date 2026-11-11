#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);    
	int n,m;
	cin>>n>>m;
	bool sp=1;//判断特殊性质A
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(sp)
		{
			ll p1=log2(a[i]),p2=log2(a[i]+1);
			if(p1==p2) sp=0;
		}
	} 
	sort(a+1,a+n+1,greater<ll>());
	ll ans=0;
	if(m==1) ans=a[1];
	else if(sp) ans=a[m]; 
	else if(m==2&&n<=3000)
	{
		for(int i=1;i<=n;++i)
		{
			ll temp=a[i];
			for(int j=i+1;j<=n;++j)
			{
				ll maxx=temp&a[j]; 
				ans=max(ans,maxx);
			}
		}
	}
	else
	{
		ans=a[1];
		for(int i=2;i<=m;++i) ans&=a[i];
	}
	cout<<ans;
	return 0;
}
//666777,没想出做法,奇数?贪心?,难度:普及
//特殊A,m=1,m=2(部分).
//万一else里的还能骗点呢
//预估:20