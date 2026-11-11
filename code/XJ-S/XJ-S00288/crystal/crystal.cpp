#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,m,a[10000005],b[10000005],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		k=1;
		while(1)
		{
			if(abs((k+1)*a[i+k]-(b[i+k]-b[i-1]))<=m&&i+k<=n)
			{
				cout<<i<<" "<<k+i<<" "<<abs((k+1)*a[i+k]-(b[i+k]-b[i-1]))<<endl;
				ans=max(ans,k+1);
				k++;
			}
			else
			break;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
