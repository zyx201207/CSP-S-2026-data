#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==1)
	{
		int ma=0;
		for(int i=0;i<n;i++)ma=max(ma,a[i]);
		cout<<ma;
		return 0;
	}
	if(m==2)
	{
		int mx=0;
		for(int i=0;i<n;i++)
			for(int j=i;j<n;j++)
				mx=(mx,a[i]&&a[j]);
		cout<<mx;
		return 0;
	}
	cout<<a[m];
	return 0;
}
