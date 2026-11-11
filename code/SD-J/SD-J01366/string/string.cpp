#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],ans=0;
char c[200001];
int main()
{	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	long long l=0,r=n;
	while(l<r)
	{	int m=min(a[l],a[r]);
		if(c[l]!=c[r])
			ans+=m;
		a[l]-=m;
		a[r]-=m;
		if(!a[l])
			l++;
		if(!a[r])
			r--;
	}
	cout<<ans;
	return 0;
}
