#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,s[10000][10000]={0},maxx=1;
int main()
{
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=1;i<=1000;i++)
    {
    	for(int j=1;j<=1000;j++)
    	{
    		s[i][j]=0x3f3f3f;
    		if(i==j)
    		{
    			s[i][j]=0;
			}
		}
	}
    cin>>c>>n>>m>>d>>q;
    int b[m+1],ans[q+1];
    for(int i=1;i<=m;i++)
    {
    	cin>>b[i];
	}
    	for(int i=1;i<=n;i++)
    	{
    		int j1;
    		cin>>j1;
    		int a,b,a1,b1;
			cin>>a>>b>>a1>>b1;
			if(s[a][a1]==0){
				s[a][a1]=0x3f3f3f3f;
			}
			s[a][a1]=min(s[a][a1],(b+b1));
			if(a1>maxx)
			{
				maxx=a1;
			}
			if(a>maxx)
			{
				maxx=a;
			}
			for(int j=1;j<=maxx;j++)
			{	
				s[a][j]=s[j][a]=min(s[a][a1]+s[a1][j],s[a][j]);
			}
		}
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			ans[i]=b[x]+b[y]+s[x][y];
		}
		cout<<endl;
		for(int i=1;i<=q;i++)
		{
			cout<<ans[i]<<endl;
		}
	return 0;
}
