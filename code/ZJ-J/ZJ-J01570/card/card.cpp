#include<bits/stdc++.h>
using namespace std;
const int N=3e5+7;
struct node
{
	int x;
	int pre, nxt;
}a[N];
int n,m,st[N];
int check(int j)
{
	for(int i=n;i>=j+1;i--)
	{
		if(a[i].x==a[j].x)return i;
	}
	return -1;
}
void prove(int z,int y)
{
	int l=a[z].pre;
	a[l].nxt=y;
	a[y].pre=l;
	a[z].pre=0,a[z].nxt=0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	  cin>>n>>m;
	  for(int i=1;i<=n;i++)cin>>a[i].x;
	  a[0].nxt=a[1].x,a[n].nxt=0;
	  for(int i=2;i<=n-1;i++)a[i].pre=i-1,a[i].nxt=i+1;
	  for(int i=1;i<=n;i++)
	  {
			int k=n-i+1;
			for(int j=k;j<=n;j++)
			{
				if(check(j))
				{
					int q=check(j);
					prove(j,q);
				}
				if(j==n)
				{
					st[a[j].x]++;
					while(a[j].pre)j=a[j].pre,st[j]++;
					break;
				}
			}
	  }
	for(int i=1;i<=m;i++)cout<<st[i];
	return 0;
}
