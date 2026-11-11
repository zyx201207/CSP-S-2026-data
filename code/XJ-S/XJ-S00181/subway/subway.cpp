#include<bits/stdc++.h>
using namespace std;
long long int sum,i,j,c,n,m,d,q,k,tt[500005],w[500005],x[500005],t[5005][5005],g[5005][5005],qi,zhong;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)
	 cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
	 	 cin>>x[j]>>tt[j];
	 	for(j=1;j<=k;j++)
	 	 g[i][x[j]]=tt[j];
	}
	for(i=1;i<=q;i++)
	{
		sum=0;
		cin>>qi>>zhong;
		sum=w[qi]+w[zhong];
		sum+=g[qi][qi]+g[zhong-1][zhong];
		/*int minn=INT_MAX;
		for(j=1;j<=k;j++)
		{
			minn=g[qi][qi+j]+g[qi+j][qi+j];
			if(minn>g[qi][qi+j-1]+g[qi+j-1][qi+j-1])
			{
				minn=g[qi][qi+j-1]+g[qi+j-1][qi+j-1];
				qi+=j;
			}
		}
		sum+=minn;*/
		while(g[qi][qi+1]!=0&&qi!=zhong-1)
		{
			sum+=g[qi][qi+1]+g[qi+1][qi+1];
			qi+=1;
		}
		cout<<sum<<endl;
	}
	return 0;
}
