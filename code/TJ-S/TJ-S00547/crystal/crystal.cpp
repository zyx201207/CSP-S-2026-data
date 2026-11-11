#include <bits/stdc++.h>
using namespace std;
long long a[500033];
long long v[500033]; 
int main() {
	long long n,m,i,j,k=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n-1;i++)
	{
		memset(v,sizeof(int),0);
		for(j=i+1;j<=n;j++)
		{
			v[j]=v[j-1]+(a[j]-a[j-1])*(j-i);
			if(v[j]>m) 
				break;
			else if(v[j]<=m)
			{
				k=max(k,j-i+1);
			}
		}
	}
	cout<<k;
	return 0;
}
