#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,maxn=-1000000,a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			ll cd=(a[i])and(a[j]);
//			cout<<a[i]<<' '<<a[j]<<' '<<int(int(a[i]) and int(a[j]))<<endl;
			if(cd>maxn)
			{
				maxn=cd;
			}
		}
	}
	cout<<maxn;
	return 0;
} 

