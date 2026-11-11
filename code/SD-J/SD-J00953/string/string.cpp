#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	long long cnt=0;
	while(l<r)
	{
		if(c[l]==c[r])
		{
			int o=min(a[l],a[r]);
			a[l]-=o;
			a[r]-=o;
		}
		else
		{
			int o=min(a[l],a[r]);
			cnt+=o;
			a[l]-=o;
			a[r]-=o;
		}
		if(a[l]==0)
		{
			l++;
		 } 
		 if(a[r]==0)
		 {
		 	r--;
		 }
	}
	cout<<cnt;
	return 0;
}
