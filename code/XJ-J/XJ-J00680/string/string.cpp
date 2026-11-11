#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	long long ans=0;
    int n,a[200005][2];
	cin>>n;
	for(int i=1;i<=n;i++)
	scanf("%d %s",&a[i][1],&a[i][0]);
	for(int i=1,j=n;i<j;)
	{
		if(a[i][0]==a[j][0])
		{
			a[i][1]-=min(a[i][1],a[j][1]);
			a[j][1]-=min(a[i][1],a[j][1]);
			if(a[i][1]==0) i++;
			if(a[j][1]==0) j--;
		}
		else
		{
			ans+=min(a[i][1],a[j][1]);
			a[i][1]-=min(a[i][1],a[j][1]);
			a[j][1]-=min(a[i][1],a[j][1]);
			if(a[i][1]==0) i++;
			if(a[j][1]==0) j--;
		}
	}
	cout<<ans;
	return 0;
}