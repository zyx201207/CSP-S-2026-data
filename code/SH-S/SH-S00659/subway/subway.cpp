#include<bits/stdc++.h>
using namespace std;
const int N=6e3+1,INF=1e8;
long long ans=0;
int c,n,m,d,l[N],r[N],q,w[N],a,t,u,s,e,minn;
int f[N][N],graph[N];
void turn_station(int station,int line,int num){
	if(graph[station]<num) return;
	graph[station]=num;
	if(station==s)num+=f[line][station];
	for(int i=1;i<=m;i++){
		if(f[line][i]<INF&&i!=station){
			if(i==e){
				num+=f[line][i];
				if(num!=0)minn=min(minn,num);
				return;
			}
			//turn_line(i,line,num);
			for(int k=1;k<=n;k++){
				if(f[k][i]!=INF&&k!=line){
					turn_station(i,k,num+f[k][i]+f[line][i]);
				}
			}
		}
	}
}
int main(){
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	fin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++) fin>>w[i];//进站台时间 
	for(int i=1;i<=n;i++){
		fin>>u;
		for(int j=1;j<=u;j++){
			fin>>a>>t;
			f[i][a]=t;
		}
	}
	for(int i=1;i<=q;i++){
		fin>>s>>e;
		minn=INF;
		memset(graph,127,sizeof(graph));
		for(int j=1;j<=n;j++){
			if(f[j][s]<INF-5){
				turn_station(s,j,0);
			}
		}
		fout<<minn+w[e]+w[s]<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
