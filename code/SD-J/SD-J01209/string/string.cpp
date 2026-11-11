#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int cnt=0;
	int l=0,r=n-1;
	while(cnt<=sum/2&&l!=r)
	{
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])ans+=a[r];
			cnt+=a[r];
			a[l]-=a[r];
			r--;
		}
		else
		{
			if(c[l]!=c[r])ans+=a[l];
			cnt+=a[l];
			a[r]-=a[l];
			l++;
		}
//		cout<<l<<' '<<r<<'\n';
	}
	cout<<ans;
	return 0;
}
//   02 01A 03 01A

/*

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
