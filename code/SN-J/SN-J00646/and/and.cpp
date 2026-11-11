//吕思齐  西安翱翔中学  SN-J00646
#include <bits/stdc++.h>
using namespace std;
int m,n;
int a[200020];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	printf("%d",a[n+1-m]);
}
