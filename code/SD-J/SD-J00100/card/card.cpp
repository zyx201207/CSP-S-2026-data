#include<bits/stdc++.h>
using namespace std;
long long int n,m;
int a[500100];
struct node{
	bool f;
	long long int x;
};
//标记 
long long int cp[500100];//计数 
void solve(node s[],long long int xx)
{
	for(long long int i=xx;i<=n;i++)
	{
		s[a[xx]].f=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long int l=1;l<=n;l++)
	{	
		node s[500100];
		for(long long int i=l;i<=n;i++)
		{
			if(s[a[i]].f==1)
			{
				solve(s,s[a[i]].x);
			}
			s[a[i]].x=i;
			s[a[i]].f=1;
		}
		for(long long int i=1;i<=m;i++)
		{
			if(s[i].f==1) cp[i]++;
		}
	}
	for(long long int i=1;i<=m;i++)
	{
		cout<<cp[i]<<" ";
	}
	return 0;
}
