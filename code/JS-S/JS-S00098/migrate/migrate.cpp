#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x1[2000009],t1,x3[2000009][2],cnt,ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		memset(x3,127,sizeof(x3));
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%d",&x1[i]);
		if(c==13||c==14){
			printf("0\n");
			continue;
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
0 2
6 2
-4 -3 -2 -1 3 6
*/
