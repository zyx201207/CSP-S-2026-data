#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;

	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	
	int mx=1;
	int l=1;
	long long lst=0;
	for(int r=2;r<=n;r++)
	{
		long long nw=lst+(r-l)*(a[r]-a[r-1]);
		while(nw>m&&r>l)
		{
			nw-=a[r]-a[l];
			l++;
		}
		mx=max(mx,r-l+1);
		lst=nw;
	} 
	
	cout<<mx<<"\n";
	return 0;
}