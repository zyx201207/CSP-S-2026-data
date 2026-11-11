#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 2e5+7;
int n,m,top;
long long ans,a[N],b[N],c[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	top=n;
	for(int j=30;j>=0;j--)
	{
		int cnt=0,tmps=0;
		for(int i=1;i<=top;i++)
		{
			if(b[i]&(1<<j))
			{
				cnt++;
				c[++tmps]=b[i];
			}
		}
		if(cnt<m)continue;
		if(cnt>=m)ans+=(1<<j);
		for(int i=1;i<=tmps;i++)b[i]=c[i];
		top=tmps;
	}
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
 }

