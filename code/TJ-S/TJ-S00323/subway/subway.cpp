#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
int k;
long long w[500005],a[505][50005],t[505][50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	long long tt=1e9;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
			int f;
			int g;
		    for(int j=1;j<=k;j++)
		    {
			    if(a[i][j]==x) 
			    {
			    	f=i;
			    	g=j;
				}
			    if(a[f][j]==y)
			    {
			    	tt=min(tt,w[x]+w[y]+t[f][g]+t[f][j]);
				}
		    }
	    }
	    cout<<tt<<endl;
	}
	return 0;
}

