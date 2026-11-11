#include<bits/stdc++.h>
using namespace std;

int c,t,n,k;
int w[2000000][2];

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&c,&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<n-1;i++)
		{
			scanf("%d %d",&w[2*i][0],&w[2*i][1]);
			w[2*i+1][0]=w[2*i][1];
			w[2*i+1][1]=w[2*i][0];
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
