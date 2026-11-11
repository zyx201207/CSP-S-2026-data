#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans;
    for(int i=1,j=2;max(i,j)<=n;i++)
    {
    	while(j<=n&&a[j]-a[i]<=m)++j;
    	if(a[i]=a[j]&&j<=n)++ans,++j;
	}
	cout<<n-ans+1<<endl;
	return 0;
}
