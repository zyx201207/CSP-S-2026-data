#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
struct node
{
	char c;
	long long num;
}a[200005],b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	ios::sync_with_stdio(false);
 	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
	}
	for(int i=1;i<=n;i++)
	{
		b[i].c=a[n-i+1].c;
		b[i].num=a[n-i+1].num;
	}
	int hh=1;
	for(int i=1;i<=n;i++)
	{
		int lst=b[i].num;
		while(lst>=a[hh].num)
		{
			if(a[hh].c!=b[i].c)
			{
				ans+=a[hh].num;
			}
			lst-=a[hh].num;
			hh++;
		}
		if(a[hh].c!=b[i].c)
		{
			ans+=lst;
		}
		a[hh].num-=lst;
	}
	ans/=2;
	cout<<ans;
 	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
//还有时间，重构吧