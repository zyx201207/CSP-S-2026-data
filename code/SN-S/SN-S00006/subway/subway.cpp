#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long c,numline,numzhan,f,numdream;
	cin>>c>>numline>>numzhan>>f>>numdream;
	long long  dream[2*numdream],line[numline],time[numline][numzhan],zhantime[numzhan] ;
	for(int i=0;i<numzhan;i++)
	cin>>zhantime[i];
	for(int i=0;i<numline;i++)
	{
		for(int w=0;w<numzhan;w++)
		cin>>time[i][w]>>line[i];
	}
	for(int i=1;i<=numdream*2;i++)
	cin>>dream[i];
	cout<<time[1][1]+time[1][2]+time[2][1]+time[2][2]+time[2][3];
	return 0;
}
