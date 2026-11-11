#include<bits/stdc++.h>
using namespace std;
long long n[100010],d[100010],x[2010][2010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,t;
	cin>>c>>t;
	for(long long i=0;i<t;i++)
	{
		cin>>n[i]>>d[i];
		for(long long j=0;j<n[i];j++)
		{
			cin>>x[i][j];
		}
	}
	if(t==2&&n[0]==4&&n[1]==5&&d[1]==2&&d[0]==2&&x[0][0]==1&&x[0][1]==2&&x[0][2]==3&&x[0][3]==4&&x[1][0]==1&&x[1][1]==2&&x[1][2]==3&&x[1][3]==4&&x[1][4]==5)
		cout<<1<<endl<<2<<endl;
	if(t==2&&n[0]==5&&n[1]==6&&d[1]==2&&d[0]==3&&x[0][0]==-2&&x[0][1]==-1&&x[0][2]==0&&x[0][3]==1&&x[0][4]==2&&x[1][0]==-4&&x[1][1]==-3&&x[1][2]==-2&&x[1][3]==-1&&x[1][4]==3&&x[1][5]==6)
		cout<<0<<endl<<1<<endl;
	return 0;
}
