#include<iostream>
#include<vector>
using namespace std;
int n,m;
int a[500010];
int c[300010];
int f[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int> w;
	for(int i=1;i<=n;i++)
	{	
		cin>>a[i];	
	}
	for(int h=1;h<=n;h++)
	{
		fill(f+1,f+n+1,0);
		for(int i=h;i<=n;i++)
		{
			if(f[a[i]]==0)
			{
				w.push_back(a[i]);
				f[a[i]]=1;
			}
			else
			{
				for(int e=w.size();e>0;e--)
				{
					if(w[e]!=a[i])
					{
						f[w[e]]=0;
						w.pop_back() ;
					}
					else
					{
						break;
					}
				}
			}
		}
		for(int o=1;o<=w.size();o++)
		{
			c[w[o]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
}
