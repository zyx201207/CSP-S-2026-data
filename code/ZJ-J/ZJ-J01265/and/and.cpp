#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y;
}a[200005];
bool cmp(node p,node q)
{
	if(p.y==q.y)
		return p.x<q.x;
	return p.y<q.y;
	
}
int n,m,b[200005],ans;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		b[i]=a[i].x;
		int x=a[i].x,cnt=0;
		while(x>=1)
		{
			if(x%2==1)
				cnt++;
			x/=2;
		}
		a[i].y=cnt;
	}
	sort(b+1,b+n+1);
	int sum=b[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		sum&=b[i];
	}
	sort(a+1,a+n+1,cmp);
//	cout<<a[n].x<<" "<<a[n].y<<endl;
	ans=a[n].x;
	for(int i=n-1;i>=n-m+1;i--)
	{
//		cout<<ans<<" "<<a[i].x<<" "<<a[i].y<<endl;
		ans=ans&a[i].x;
	}
	cout<<max(sum,ans);
	return 0;
}