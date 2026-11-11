#include<iostream>
#include<cstdio>
using namespace std;
const int N=5e5+10;
int a[N];
struct node
{
	bool b;
	int pos1,pos2,pos3;
}k[N];
int ans[N];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		if(k[a[i]].b&&pos)
		{
			for(int j=k[a[pos]].pos2-1;j>=k[a[pos]].pos3+1;j--)
			{
				int t=0;
				ans[a[j]]-=++t;
			}
			k[a[pos]].pos3=k[a[pos]].pos2;
			cout<<k[a[pos]].pos3<<" "<<k[a[pos]].pos2<<endl;
		}
		if(!k[a[i]].b&&!pos)
		{
			ans[a[i]]=i;
			k[a[i]].b=1;
			k[a[i]].pos1=i;
			k[a[i]].pos3=k[a[i]].pos1;
			continue;
		}
		if(k[a[i]].b&&!pos)
		{
			ans[a[i]]=i;
			k[a[i]].b=1;
			pos=i;
			k[a[i]].pos2=i;
			continue;
		}
		if(!k[a[i]].b&&pos)
		{
			int l=k[a[pos]].pos1,r=k[a[pos]].pos2; 
			ans[a[i]]=i;
			k[a[i]].b=1;
			continue;
		}
		if(k[a[i]].b&&pos)
		{
			ans[a[i]]=i;
			pos=i;
			k[a[i]].pos2=i;
		}
		
	}
	for(int i=1;i<=m;i++) cout<<ans[i];
	return 0;
 }
/*
if(!k[a[i]].b&&!pos)
		{
			ans[a[i]]=i;
			k[a[i]].b=1;
			k[a[i]].pos1=i;
		}
		if(k[a[i]].b&&!pos)
		{
			ans[a[i]]=i;
			k[a[i]].b=1;
			pos=i;
			k[a[i]].pos2=i;
		}
		if(!k[a[i]].b&&pos)
		{
			int l=k[a[pos]].pos1,r=k[a[pos]].pos2; 
			ans[a[i]]=i;
			k[a[i]].b=1;
		}
*/
