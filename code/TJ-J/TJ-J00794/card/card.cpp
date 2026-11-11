#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,m,a[N],tong[N],ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tong[a[i]]++;
	}
	int sum=0;
	for(int i=m;i>=1;i--)
	{
		if(tong[i]%2==0)
		{
			ans[i]=tong[i]/2;
			sum+=tong[i];
		}
		else 
		{
			ans[i]=n-sum-tong[i]/2;
			break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
