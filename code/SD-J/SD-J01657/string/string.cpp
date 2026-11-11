#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n,a1=a[1],a2=a[n];
	long long ans=0;
	while(l<r)
	{
		if(c[l]!=c[r])
			ans+=min(a1,a2);
		int a3=a1;
		if(a1<=a2) 
			a1=a[++l];
		else a1-=a2;
		if(a2<=a3)
			a2=a[--r];
		else a2-=a3;
	}
	cout<<ans;
	return 0;
}
