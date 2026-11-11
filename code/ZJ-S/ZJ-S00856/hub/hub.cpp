#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int c,t,n,k;
void solve()
{
	scanf("%d%d",&n,&k);
	if(c==13||c==14)
	{
		int m=(n-1)/2;
		if(k==n)
		{
			printf("0\n");
			return ;
		}
		printf("%d\n",max(1,(m-k+1)+1));
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
		solve();
	return 0;
}


