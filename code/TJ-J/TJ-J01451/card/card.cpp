#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100009];
int b[100009];
int v[100009];
int ans[100009];
int p[100009];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int h=1,t=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(v[a[j]]){
				int f;
				for(int k=h;k<=t;k++)
				{
					if(b[k]==a[j])
					{
						f=k;
						break;
					}
				}
				int l=t;
				for(int k=f;k<=t;k++)
				{
					v[b[k]]--;
					b[k]=0;
					l--;
				} 
				t=l;
			}
			v[a[j]]++;
			b[++t]=a[j];
		}
		for(int j=h;j<=t;j++)
		{
			ans[b[j]]++;

		}
		h=1,t=0;
		memset(v,0,sizeof(v));
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
 } 
