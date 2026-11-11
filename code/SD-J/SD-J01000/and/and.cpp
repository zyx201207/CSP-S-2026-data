#include<bits/stdc++.h> 
using namespace std;
long long maxn,n,m,b,cnt;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b=a[i];
		cnt=1;
		for(int j=1+i;j<=n;j++)
		{
			if(cnt!=m)
			{
				b=b&a[j];
				cnt++;
			}
			else
			{
				break;
			}
		}
		maxn=max(b,maxn);
	}
	cout<<maxn;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
