#include<bits/stdc++.h>
#define int long long
using namespace std;
int map1[1000010];
int map2[1000010];
void read()
{
	int n,k;//城市数量,基地数量 
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<n;i++)
	{
		scanf("%lld%lld",&map1[i],&map2[i]);
	}
	cout<<map1[n-1]/2;
} 
signed main()
{
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c,t;
	scanf("%lld%lld",&c,&t);
	for(int i=1;i<=t;i++)
	{
		read();
	}
	return 0;
} 