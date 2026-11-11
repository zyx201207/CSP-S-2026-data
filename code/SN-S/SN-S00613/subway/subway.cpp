#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const int DNF=0x3f3f3f3f;
int c,n,m,d,q;//地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[N],a[N][N],t[N][N],dist[N][N],k[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];//做地铁前
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j][i]>>t[j][i];
			dist[a[j-1][i]][a[j][i]]=t[j][i];
			dist[a[j][i]][a[j][i]]=0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int x=1;x<=k[i];x++)
				for(int y=1;y<=k[j];y++)
				{
					if(a[x][i]==a[y][j]) dist[a[x][i]][a[y][j]]=t[y][j];
				}
	//cout<<"rugh"<<dist[1][1]<<"\n";
	//flod
	for(int fg=1;fg<=2;fg++)
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++){
	//			if(i==3&&j==6) cout<<"udijrhgu!!!!!";
				if(dist[i][k]<DNF&&dist[k][j]<DNF){
	//				cout<<"("<<dist[i][j]<<"["<<i<<" "<<j<<"]"<<"-->"<<dist[i][k]+dist[k][j]+dist[k][k]<<"["<<i<<" "<<k<<' '<<j<<"]";
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]+dist[k][k]);
	//				cout<<"="<<dist[i][j]<<")\n";
				}	
			}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
//		cout<<"riut"<<dist[1][2]+dist[2][2]+dist[2][3]+dist[3][3]+dist[3][6];
		int danpu=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k[i];j++)
			if(a[j][i]==x) {
				danpu=t[j][i];
				break;
			}
		}
		long long ams=dist[x][y]+w[x]+w[y]+danpu;
		if(ams>DNF) ams-=DNF;
		cout<<ams<<endl;
	}
	 
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
