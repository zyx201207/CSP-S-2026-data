#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a;
	char b[100005]; 
}q[2000005];
long long int i,j,n,m,maxn=0,c,s[200005][200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>q[i].a;
		c=q[i].a;
		maxn=max(maxn,c);
	}
	
	cout<<maxn;
	return 0;
}
