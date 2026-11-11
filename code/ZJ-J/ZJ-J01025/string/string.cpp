//- Evanescent -
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n;
int a[N];
char c[N];
int top1,top2;
int cnt;
int l;
int ans;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int mid=l/2;
	top2=n;
	top1=1;
	while(cnt<mid)
	{
		cnt+=min(a[top1],a[top2]);
		int x=min(a[top1],a[top2]);
		if(c[top1]!=c[top2])
		{
			ans+=x;
		}
		if(x==a[top1])
		{
			top1++;
		}
		else
		{
			a[top1]-=x;
		}
		if(x==a[top2])
		{
			top2--;
		}
		else
		{
			a[top2]-=x;
		}
	}
	cout<<ans;
	return 0;
}