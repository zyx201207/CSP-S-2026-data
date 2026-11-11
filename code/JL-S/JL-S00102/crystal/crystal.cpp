#include<bits/stdc++.h>
using namespace std;
int num[5009][5009],a[5009],b[5009];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i]>=a[j])
				num[i][j]=a[i]-a[j];
			else
				num[i][j]=1e9;
	for(int i=1;i<=n;i++)
		sort(num[i]+1,num[i]+n+1);
	for(int i=1;i<=n;i++)
	{
		int sum=0,numm=0;
		for(int j=1;j<=n&&sum<=m;j++)
			sum+=num[i][j],numm++;
		b[i]=numm-1;
	}
	sort(b+1,b+n+1);
	reverse(b+1,b+n+1);
	cout<<b[1];
	return 0;
}
