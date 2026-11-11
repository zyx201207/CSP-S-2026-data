#include<bits/stdc++.h>
using namespace std;
int n,a[210000],l,r;
long long ans;
char b[210000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	l=1;r=n;
	while(1)
	{
		if(l>=r)
			break;
		int m=min(a[l],a[r]);
		a[l]-=m;a[r]-=m;
		if(b[l]!=b[r])
			ans+=m;
		if(a[l]==0)
			l++;
		if(a[r]==0)
			r--;
	}
	cout<<ans;
	
	return 0;
}
