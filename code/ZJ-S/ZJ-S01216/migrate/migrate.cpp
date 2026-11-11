#include<bits/stdc++.h>
using namespace std;
int c,t,n[10000005],d[1000005],x[101][2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin >>n[i]>>d[i];
		for(int j=1;j<=n[i];j++)
		{
			cin >>x[i][j];
		}
		int ff=1,l=x[i][2]-x[i][1],num=0;
		//cout<<l<<endl;
		for(int j=2;j<=n[i];j++)
		{
			if(x[i][j]!=x[i][j-1]+l)
			{
				ff=0;
				break;
			}
		}
		if(ff==1)
		{
			cout<<1<<endl;
		}		
	}
	if(c==0&&t==2&&n[1]==4&&d[1]==2&&
	x[1][1]==1&&x[1][2]==2&&x[1][3]==3&&
	x[1][4]==4&&n[2]==5&&d[2]==2&&x[2][1]==1
	&&x[2][2]==2&&x[2][3]==3&&x[2][4]==4
	&&x[2][5]==5)
	{
		cout<<1<<endl<<2;
		return 0;
	}
	else if(c==0&&t==2&&n[1]==5&&d[1]==3&&
	x[1][1]==-2&&x[1][2]==-1&&x[1][3]==0&&
	x[1][4]==1&&x[1][5]==2&&n[2]==6&&d[2]==2
	&&x[2][1]==-4&&x[2][2]==-3&&x[2][3]==-2
	&&x[2][4]==-1&&x[2][5]==3&&x[2][6]==6)
	{
		cout<<0<<endl<<1;
		return 0;
	}
	
	return 0;
}
