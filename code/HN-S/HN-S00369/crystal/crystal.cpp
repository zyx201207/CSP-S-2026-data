#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005];
long long m;
long long ans=0,maxx=-1e9;
struct F
{
	int num;
	int c;
}f[500005];
bool cmp(F x,F y)
{
	return x.c<y.c;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i].num=i;
	}
	int idx;
	for(int i=1;i<=n;i++)
	{
		ans=0;
		for(int j=1;j<=n;j++)
		{
			f[j].c=abs(a[i]-a[f[j].num]);
		}
		sort(f+1,f+n+1,cmp);
		for(int j=1;j<=n;j++)
		{
			//cout<<"f["<<j<<"].c:"<<f[j].c<<"\n";
		}
		idx=m;
		for(int j=1;j<=n;j++)
		{
			if(idx<=0)
			{
				break;
			}
			if(idx>=f[j].c)
			{
				ans++;
				idx-=f[j].c;
			}
			else
			{
				break;
			}
		//	cout<<"idx: "<<idx<<"\n";
		}
		//cout<<"a[i]:"<<a[i]<<" ans:"<<ans<<"\n";
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
