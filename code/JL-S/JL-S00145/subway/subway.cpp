#include<bits/stdc++.h>
using namespace std;
long long sj[200],jiao12,jiao23,jiao13;
long long hi[20][22];
bool flag[22][22];
int main()
{	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>sj[i];
	for(long long i=1;i<=n;i++)
	{
		long long k,jg,ff;
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			cin>>jg>>ff;
			flag[i][jg]=true;
			hi[i][jg]=ff;
		}
	}
	jiao12=0;
	jiao13=0;
	jiao23=0;
	for(long long i=1;i<=m;i++)
	{	if(flag[1][i]==true&&flag[2][i]==true){
			if(jiao12==0||(hi[1][jiao12]+hi[2][jiao12]>hi[1][m]+hi[2][m]))
				jiao12=i;
			}
		if(flag[2][i]==true&&flag[3][i]==true)
		{
			if(jiao23==0||(hi[2][jiao23]+hi[3][jiao23]>hi[2][m]+hi[3][m]))
			jiao23=i;
		}
		if(flag[3][i]==true&&flag[1][i]==true)
		{
			if(jiao13==0||(hi[1][jiao13]+hi[3][jiao13]>hi[1][m]+hi[3][m]))
			jiao13=i;
		}
	}long long x,y;
	for(long long l=0;l<q;l++)
	{
	cin>>x>>y;
	long long ma=LONG_LONG_MAX;
	if(flag[1][x]&&flag[1][y])
	{
		ma=min(ma,sj[x]+sj[y]+hi[1][x]+hi[1][y]);
	}
	if(flag[2][x]&&flag[2][y])
	{
		ma=min(ma,sj[x]+sj[y]+hi[2][x]+hi[2][y]);
	}
	if(flag[3][x]&&flag[3][y])
	{
		ma=min(ma,sj[x]+sj[y]+hi[3][x]+hi[3][y]);
	}
	if(jiao12!=0&&flag[1][x]&&flag[2][y])
	{
		ma=min(ma,sj[x]+sj[y]+hi[1][jiao12]+hi[2][jiao12]+hi[1][x]+hi[2][y]);
			}
		if(jiao12!=0&&flag[2][x]&&flag[1][y])
	{
		ma=min(ma,sj[x]+sj[y]+hi[1][jiao12]+hi[2][jiao12]+hi[2][x]+hi[1][y]);
		
	}
	if(jiao23!=0&&flag[2][x]&&flag[3][y])
	{
		ma=min(ma,sj[x]+sj[y]+hi[2][jiao23]+hi[3][jiao23]+hi[2][x]+hi[3][y]);
		
	}
	if(jiao23!=0&&flag[3][x]&&flag[2][y])
	{
		ma=min(ma,sj[x]+sj[y]+hi[2][jiao23]+hi[3][jiao23]+hi[3][x]+hi[2][y]);
		
	}
	if(jiao13!=0&&flag[3][x]&&flag[1][y])
	{
		ma=min(ma,sj[x]+sj[y]+hi[3][jiao13]+hi[1][jiao13]+hi[3][x]+hi[1][y]);
		
	}
	if(jiao13!=0&&flag[1][x]&&flag[3][y])
	{
		ma=min(ma,sj[x]+sj[y]+hi[3][jiao13]+hi[1][jiao13]+hi[1][x]+hi[3][y]);
	
	}
	cout<<ma<<endl;
	}
	return 0;
}
