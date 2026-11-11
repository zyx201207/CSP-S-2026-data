#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long cnt[N],a[N];
char c[N];
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int h;

	for(int i=1;i<=n;i++)
	{
		cnt[i]=a[i]&a[i-1];
	}
	int maxx=0;
	for(int i=2;i<=n+1;i++)
	{
		if(cnt[i]>=cnt[i-1])
		{
			maxx=cnt[i];
		}
	}
	cout<<maxx;
	return 0;
}
