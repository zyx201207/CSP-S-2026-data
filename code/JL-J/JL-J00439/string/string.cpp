#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[200005],x,y,ans;
char b[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	x=1;
	y=n;
	while(x<y)
	{
		a[x]--;
		a[y]--;
		if(b[x]!=b[y]) ans++;
		if(a[x]==0) x++;
		if(a[y]==0) y--;
	}
	cout<<ans;
	return 0;
}
