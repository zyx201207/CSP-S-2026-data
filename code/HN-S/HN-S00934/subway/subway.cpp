#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int w[1000005],a[10005][10005],t[10005][10005],minn[1000005],id[1000005];
int main()
{
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
	    cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			if(t[i][j]<minn[j])
			{
				minn[j]=t[i][j];
				id[j]=i; 
			}
		}	
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int num=w[x]+minn[x]+minn[y]+w[y];
		if(id[x]==id[y])
		{
			cout<<num<<endl;
		}
		else
		{
			int time=1e9,time1=1e9;
		    for(int d1=1;d1<=d;d1++)
		    { 
			    for(int d2=1;d2<=d;d2++)
			    {
				    if(a[id[x]][d1]==a[id[y]][d2])
				    {
					    time1=t[id[x]][d1]+t[id[y]][d2];
				    }
				    time=min(time,time1);
			    }  
		    }
		    cout<<num+time<<endl;
	    }
	}
	return 0;
} 
