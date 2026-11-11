#include<bits/stdc++.h>
using namespace std;
#define sub
//n 2e6
//dp n^2
#define ull unsigned long long
#define ll long long
#define ud unsigned
const int MAX=2.1e6;
int c,times;
int fr[MAX];//在i位置的鸟能飞到的最远距离
ll a[MAX];
ll ans;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#ifdef sub
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	cin>>c>>times;
	while(times--)
	{
		memset(fr,0,sizeof fr);
		ans=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ll t=0;
		for(int l=1,r=1;;)
		{
			if(r<=n&&a[r+1]-a[r]+t<=d)
			{
				r++;
				t+=a[r]-a[r-1];
			}
			else
				l++,t-=a[l]-a[l-1];
			fr[l]=r;
			if(l==n)
				break;
		}//计算fr
		for(int i=1;i<=n;i++)
		{
			int b=fr[i],c=min(fr[b],fr[b-1]);
			if(fr[b-1]==c&&fr[b-2]<c)//计入ans
				ans+=c-b;
		}
		cout<<ans<<'\n';
	}
}