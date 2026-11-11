#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lnt long long
#define deb(x) cerr<<"Debug : LINE = "<<__LINE__<<" --> "<<#x<<" = "<<x<<endl;
const lnt N=5e5+10;
lnt m,n;
lnt a[N],f[N];
void solve()
{
	cin>>n>>m;
	for(lnt i=1; i<=n; i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(lnt i=2; i<=n; i++)
		f[i]=abs(a[i]-a[i-1]);
	lnt sum=0,t=0;
	lnt l=1,r=1;
	lnt ans=0;
	while(r<=n)
	{
		while(1)
		{
//			deb(l)deb(r)deb(sum)deb(t)deb(ans)deb((r-l)*f[r])deb(t+f[r])deb(a[l])deb(a[r])
			sum+=(r-l)*f[r];
			t+=f[r];
			r++;
			if(sum<=m&&r<=n)
			{
				ans=max(ans,r-l);
//				deb(max(ans,r-l+1))deb(r-l+1)deb(r-l);
//				cout<<"-------------------"<<endl;
			}
			else
			{
//				cout<<"-------------------"<<endl;
				break;
			}
		}
		while(sum>m)
		{
//			deb(l)deb(r)deb(sum)deb(t)deb(ans)deb((r-l)*f[r])deb(t+f[r])deb(a[l])deb(a[r])
//			cout<<"-------------------"<<endl;
			sum-=t;
			t-=f[l+1];
			l++;
		}
	}
	cout<<ans<<endl;
	return ;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	lnt T=1;
//	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

