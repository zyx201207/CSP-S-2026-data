#include<bits/stdc++.h>
using namespace std;
long long dq[1110];
struct bian{long long y,w;};
long long lj[1100][1100];
vector <bian> lx;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,i,j,k,x,z;
	bian y;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;++i) for(j=1;j<=m;++j) lj[i][j]=-1;
	for(i=1;i<=m;++i) cin>>dq[i],lj[i][i]=0;
	for(i=1;i<=n;++i) 
	{
		cin>>x;
		lx.clear();
		for(j=1;j<=x;++j)
		{
			cin>>y.y>>y.w;
			lx.push_back(y);
		}
		z=lx.size();
		for(j=0;j<z;++j)
		{
			for(k=j+1;k<z;++k)
			{
				lj[lx[j].y][lx[k].y]=lj[lx[k].y][lx[j].y]=lx[j].w+lx[k].w;
			}
		}
	}//jiantu
	//f
	for(k=1;k<=m;++k)
		for(i=1;i<=m;++i)
			for(j=1;j<=m;++j)
				if(k!=i&&i!=j&&k!=j&&lj[i][k]>-1&&lj[k][j]>-1)
				{
					if(lj[i][j]==-1) lj[i][j]=lj[i][k]+lj[k][j];
					else lj[i][j]=min(lj[i][k]+lj[k][j],lj[i][j]);
				}
	for(i=1;i<=q;++i) cin>>x>>z,cout<<lj[x][z]+dq[x]+dq[z]<<"\n";
	return 0;
}
