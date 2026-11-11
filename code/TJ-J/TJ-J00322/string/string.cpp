#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int x;
	char s;
}a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=1,r=0,m=1,m2=n;
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i].x>>a[i].s;
		r+=a[i].x;
	}
	int sum=0;
	while(l<r)
	{
		int minn=min(a[m].x,a[m2].x);
		if(a[m].s!=a[m2].s)
			sum+=minn;
		a[m].x-=minn;
		a[m2].x-=minn;
		l+=minn,r-=minn;
		if(a[m].x==0) m++;
		else m2--;
	}
	cout<<sum;
	return 0;
}
