#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int t=m,ans=0;
	while(t!=0)
	{
		int f=0;
		for(int i=1;i<=n;i++)
		{
			t--;
			f=f&a[i];
		}
		ans=max(ans,f);
	}
	cout<<ans;
	return 0;
}

