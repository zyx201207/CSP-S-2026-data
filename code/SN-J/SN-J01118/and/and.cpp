#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=-1;
int a[100005];
void www(int q, int o,int l,int k)
{
	if(l==0||o>n)
	{
		maxx=max(q,maxx);
		return;	
	}	
	
	for(int i=1;i<=l;i++)
	{
		www(q&a[o],o+i,l-1,1);
	}
	//xhy
}	
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	/*for(int i=1;i<=n;i++)
	{
		int p=a[i];
		for(int j=i+1;j<=n;j++)
		{
			for(int z=0;z<m-1;z++){
				p&=a[j+z];
				maxx=max(p,maxx);
			}
		}	
	} */
	for(int i=1;i<=n;i++)
	{
		
		www(a[i],2,m,1);
	}
	cout<<maxx;
	return 0;
}
