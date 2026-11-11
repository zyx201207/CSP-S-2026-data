#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,cnt,minn;
struct Node
{
	long long t;
	char ch;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld%s",&a[i].t,&a[i].ch);
	for(int i=1,j=n;i<j;)
	{
		minn=min(a[i].t,a[j].t);
		if(a[i].ch!=a[j].ch)
			cnt+=minn;
		a[i].t-=minn;
		a[j].t-=minn;
		if(a[i].t==0) i++;
		if(a[j].t==0) j--;
	}
	cout<<cnt;
	return 0;
}
