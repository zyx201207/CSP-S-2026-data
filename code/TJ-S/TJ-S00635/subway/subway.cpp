#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	while(q--)
	{
		printf("%d",c+m+q);
	}
	return 0;
}
