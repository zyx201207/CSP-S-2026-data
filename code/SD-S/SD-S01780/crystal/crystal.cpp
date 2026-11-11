#include<bits/stdc++.h>
#define int long long
using namespace std;

//inline int read()
//{
//	int x=0,f=1;
//	char c=getchar();
//	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
//	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
//	return x*f;
//}
const int N=5*1e5+10;
int n,m;
int a[N],b[N];
int maxx=0;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		b[i]=a[i]-a[i-1];
		a[i-1]=b[i]+a[i-2];
	}
	
	int sum=0;
	for(int head=1,hail=2;hail<=n;hail++)
	{
		sum+=(hail-head+1)*b[hail];
		while(sum>m)
		{
			sum-=a[hail-1]-a[head-1];
			head++;
		}
		maxx=max(maxx,hail-head+2);
	}
	cout<<maxx;
	
	return 0;
}
