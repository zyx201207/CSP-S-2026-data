#include <bits/stdc++.h>
using namespace std;
long long a[200001];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	num=a[1];
	for (int i=2;i<=m;i++)num&=a[i];
	printf("%lld",num);
	return 0;
}
