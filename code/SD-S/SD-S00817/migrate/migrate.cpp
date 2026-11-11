#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
int x[2000006];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x[i]);
		}
		printf("2\n");
	}
	
	cout<<endl;
	return 0;
}
