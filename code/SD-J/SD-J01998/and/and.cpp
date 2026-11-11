#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+10;
int a[N],b[N],c[N];
int n,m,t=0,ans=0;
bool st[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;++i)
		cin>>a[i];
	if (m==1)
	{
		sort(a,a+n,cmp);
		cout<<a[0];
		return 0;
	}
	else if (m==2)
	{
		for (int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				if (a[i]==a[j]) continue;
				b[t]=int(a[i]&a[j]);
				t++;
			}
		sort(b,b+t,cmp);
		cout<<b[0];
		return 0;
	}
	else if (m==n)
	{
		sort(a,a+n,cmp);
		ans=a[0];
		for (int i=1;i<n;++i)
			ans&=a[i];
		cout<<ans;
		return 0;
	}
	
	return 0;
}
