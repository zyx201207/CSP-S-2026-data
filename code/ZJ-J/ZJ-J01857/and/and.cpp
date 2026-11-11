#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,sum;
bool b[200005],last;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=29;i>=0;i--)
	{
		sum=0;
		for(int j=1;j<=n;j++)
		{
			if(last&&(((a[j]>>i+1)&1)==0))b[j]=1;
			if(!b[j]&&((a[j]>>i)&1))sum++;
		}
		if(sum>=m)last=1,ans+=(1<<i);
		else last=0;
	}
	printf("%d",ans);
	return 0;
}