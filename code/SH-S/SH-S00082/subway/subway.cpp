#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,b[500001],f[1001][1001],kk,aa[1001],tt[1001],l,r,av[500001]; 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
    	cin>>b[i];
	}
    if(c<=11)
    {
    	memset(f,0x3f3f3f,sizeof(f));
    	for(int i=1;i<=n;i++)
    	{
    		cin>>kk;
    		for(int j=1;j<=kk;j++)
    		{
    			cin>>aa[j]>>tt[j];
			}
			for(int x=1;x<kk;x++)
			{
				for(int y=x+1;y<=kk;y++)
				{
					if(f[aa[x]][aa[y]]>tt[x]+tt[y])
					{
						f[aa[x]][aa[y]]=tt[x]+tt[y];
						for(int u=1;u<=m;u++)
						{
							f[aa[x]][u]=f[u][aa[x]]=min(f[u][aa[y]]+f[aa[x]][aa[y]],f[u][aa[x]]);
							f[u][aa[y]]=f[aa[y]][u]=min(f[u][aa[y]],f[u][aa[x]]+f[aa[x]][aa[y]]);
						} 
					}
				}
			}
		}
		/*for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<f[i][j]<<' ';
			}
			cout<<endl;
		}*/
		for(int i=1;i<=q;i++)
		{
			cin>>l>>r;
			cout<<f[l][r]+b[l]+b[r]<<'\n';
		}
		return 0;
	}
	if(c==21||c==20)
	{
		memset(av,0x3f3f3f,sizeof(av));
		for(int i=1;i<=n;i++)
		{
			cin>>kk;
			for(int j=1;j<=kk;j++)
			{
				cin>>aa[0]>>tt[0];
				av[aa[0]]=min(av[aa[0]],tt[0]);
			}
		}
		for(int i=1;i<=q;i++)
		{
			cin>>l>>r;
			cout<<av[l]+av[r]+b[l]+b[r]<<'\n';
		}
	}
    return 0;
}

