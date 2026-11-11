#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cost,cnt=0,mx=0,flag;
int suf[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);//记得该text 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>a[1];
	for (int i=2;i<=n;i++)
	{
		cin>>a[i];
		//suf[i-1]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		suf[i-1]=a[i]-a[i-1];//sort后后缀和 
	}
	//cha=a[2]-a[1];
	flag=m;
	for (int i=0;i<n;i++)
	{
		//以i为第一个点的水晶 
		cnt=0;
		m=flag;
		while(m >=0&&cnt+i<n)
		{
			cnt++;
			//cost+=cnt;
			m=m-cnt*suf[cnt+i];
			//cout<<m<<endl;
			//cout<<cost<<endl;
		}
		//cout<<cnt<<" ";
		if (cnt>mx) mx=cnt;
	}
	cout<<mx;
	return 0;
}
