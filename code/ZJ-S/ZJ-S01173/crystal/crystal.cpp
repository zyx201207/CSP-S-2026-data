#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
pair<int,int>f[N];
long long m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int k=0; 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	f[0]={0,0};
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		for(int j=i-1;j>=k;j--)
		{
			if(f[j].second+m<a[i]*f[j].first)
			{
				k=j+1;
				break;
			}
			if(f[j].first+1>f[i].first)
			{
				f[i].first=f[j].first+1;
				f[i].second=f[j].second+a[i];
			}
			if(f[j].first+1==f[i].first and f[i].second>f[j].second+a[i])f[i].second=f[j].second+a[i];
		}
	}
	cout<<f[n].first;
	return 0;
}
