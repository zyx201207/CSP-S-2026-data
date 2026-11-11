#include<bits/stdc++.h>
using namespace std;
int n,m,maxn;long long a[200005];
bool cnt1[200005][31];
void turn(int x,long long y)
{
	long long num2=1;int cntt=1;
	while(num2<y)
	{
		num2*=2;
		cntt++;
	}
	maxn=max(maxn,cntt);
	for(int i=cntt;i>0;i--)
	{
		if(y>num2)
		{
			y-=num2;
			cnt1[x][i]=1;
		}
		num2/=2;
	}

 }
bool cmp(long long a,long long b)
{
	return a>=b;
}
int main()
{
	freopen("and.n","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=m;i++)
	{
		a[1]&=a[i];
	}
	cout<<a[1];
/*	for(int i=1;i<=n;i++)turn(i,a[i]);
	bool f=0;int ans=0;
	for(int i=maxn;i>=1&&!f;i--)
	{
		int cnt=0;
		for(int j=1;j<=n&&!f;j++)
		{
			if(cnt1[j][i])cnt++;
			if(cnt==m)
			{
				f=1;
				ans=i;
			}
		}
	}
	cout<<ans;
	long long answ;
	if(ans=0)cout<<0;
	else
	{
		long long m1[200005];int cnt3=0;
		for(int i=1;i<=n;i++)
		{
			cout<<cnt1[i][ans]<<" ";
			if(cnt1[i][ans])
			{
				cnt3++;
				m1[cnt3]=a[i];
			    cout<<m1[cnt3];
			}
		}
		answ=m1[1];
		for(int i=2;i<=m;i++)answ=answ&m1[i];
		cout<<answ;
	}*/
	return 0;
}
