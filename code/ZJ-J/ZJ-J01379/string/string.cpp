#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int a;
	char c;
}g[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>g[i].a>>g[i].c;
	int l=1,r=n;
	long long cnt=0;
	while(l<r)
	{
		if(g[l].c!=g[r].c)
		{
			cnt+=(g[l].a<g[r].a?g[l].a:g[r].a);
		}
		if(g[l].a>g[r].a)
		{
			g[l].a-=g[r].a;
			r--;
		} 
		else 
		{
			if(g[l].a<g[r].a)
			{
				g[r].a-=g[l].a;
				l++;
			} 	
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
