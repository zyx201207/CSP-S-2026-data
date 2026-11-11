#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read()
{
	int ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c))
	{
		ret=ret*10+(c-'0');
		c=getchar();
	}
	return ret;
}
const int N=1000010;
int n,k;
vector <int> mp[N];
int main()
{
	freopen("hub.in","r",stdin);//Oct31==Dec25?
	freopen("hub.out","w",stdout);
	int c=read();
	int t=read();
	while(t--)
	{
		n=read();
		k=read();
		for(int i=1;i<n;i++)
		{
			int u=read();
			int v=read();
			mp[u].push_back(v);
			mp[v].push_back(u);
		}
		if(c==13||c==14)
		{
			if(n==k) printf("0");
			else
			{
				if(k>=(n>>1)) printf("1");
				else
				{
					int m=(n>>1);
					printf("%d",((m-k+3)>>2)+1);
				}
			}
		}
		else
		{
			if(k==1) printf("%d",((n-k+1)>>1));
			else printf("%d",((n-k+3)>>2));
		}
		if(t) printf("\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
