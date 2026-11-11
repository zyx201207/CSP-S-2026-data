#include<bits/stdc++.h>
bool Med;
#define rep(i,j,k) for(int i=(j);(i)<=(k);(i)++)
#define per(i,j,k) for(int i=(j);(i)>=(k);(i)--)
#define i64 long long
#define u64 unsigned long long
#define inf 0x3f3f3f3f
#define inf64 0x3f3f3f3f3f3f3f3fll
#define pb push_back
namespace Staque{
	template<typename T,typename U>inline bool gmax(T &x,const U &y){return x<y?(x=y,1):0;}
	template<typename T,typename U>inline bool gmin(T &x,const U &y){return x>y?(x=y,1):0;}
	void Freopen(){freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);}
}using namespace Staque;
#define PII std::pair<int,int>
#define fi first
#define se second 
const int N=505,M=500005,_D=21;
int n,m,D,q,w[M],v[M];
i64 e[N][N];
std::vector<PII> pos[M];
void Init(){}
void testCase(){
	std::cin>>n>>m>>D>>q;	
	rep(i,1,m)std::cin>>w[i];
	rep(i,1,n){
		int len;std::cin>>len;
		while(len--){
			int x,y;std::cin>>x>>y;
			pos[x].pb({y,i});
		}
	}
	memset(e,0x3f,sizeof e);
	rep(i,1,n)e[i][i]=0;
	rep(i,1,m){
		int len=pos[i].size()-1;
		rep(j,0,len-1)rep(k,j+1,len){
			int x=pos[i][j].se,y=pos[i][k].se,z=pos[i][j].fi+pos[i][k].fi;
			gmin(e[x][y],z),gmin(e[y][x],z);
		} 
	}
	rep(i,1,n)rep(j,1,n)rep(k,1,n)
		gmin(e[j][k],e[j][i]+e[i][k]);
	while(q--){
		int x,y;
		std::cin>>x>>y;
		i64 res=inf64;
		int lenl=pos[x].size()-1,lenr=pos[y].size()-1;
		rep(i,0,lenl)rep(j,0,lenr){
			gmin(res,e[pos[x][i].se][pos[y][j].se]+w[x]+w[y]+pos[x][i].fi+pos[y][j].fi);
		} 
		std::cout<<res<<"\n";
	}
}
bool Mst;
int main(){
	Freopen();
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	int TC=1,CC;
	std::cin>>CC;
	while(TC--)testCase();
	fprintf(stderr,"Memory:%.3lfMB\nTime:%.3lfs\n",(&Med-&Mst)/1048576.0,clock()*1.0/CLOCKS_PER_SEC);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
