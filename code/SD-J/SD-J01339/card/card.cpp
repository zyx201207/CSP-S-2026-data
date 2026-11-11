#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=3e5+10;
ll n,m,pos=1;
int a[N],f[N],ans[N],p[N];
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
    }
    memset(f,0,sizeof(a));
    for(int j=1;j<=n;j++)
    {
    	int posl=0,l=0;
    	for(int i=1;i<=n;i++)
    	{
    		if(f[a[i]]!=0) 
			{
				l=f[a[i]]+1;
				for(int k=1;k<=posl;k++)
				{
					f[p[k]]=0;
				}
			}
    		p[++posl]=a[i];
			f[a[i]]=posl; 
        }
        for(int i=l;i<=n;i++)
        {
        	ans[p[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
