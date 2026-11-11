#include<bits/stdc++.h>
#define fst ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define inf INT_MAX
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef priority_queue<int> pq;
typedef priority_queue<int,vector<int>,greater<int> > spq; 
struct AC{
};


const int N=2e4+10;
//地铁口--站厅--各线路站台 
int c,n/*地铁线路数*/,m/*地铁站数*/,d,q,w[N],a[505][N],t[505][N],k[N];
// k[i]表示第 i 条线路经过的地铁站数量 
// w[i]表示从每个地铁站的地铁口走到站厅需要的时间 
// a[i,j]表示第 i 条线路经过的第 j 个地铁站-
// t[i,j]表示从从第i条线路走到a[i,j]站厅的时间-
bool st[505],fl[505][N];
// st[i]表示i站点是否已走过 
//fl[i,j]表示i线是否经j站 
int x,y;
LL ans,zbw=inf;
void dfs(int x,LL ans,int z){//目前处于x站厅，用时ans,从z线路来的 
	if(x==y){
		zbw=min(zbw,ans);
		return;
	}
	st[x]=1;//标记
	//换站
	for(int i=1;i<=n;i++){//遍历找能走哪些线 
		if(fl[i][x]){//有i线 
			for(int j=1;j<=k[i];j++){
				if(!st[a[i][j]]){//没走过 i线第j个 
					int tt=ans+t[i][x]+t[i][a[i][j]];
					dfs(a[i][j],tt,i);
				}
			}
		}
	}
	
	st[x]=0;//删除标记 
}
void solve(){
	ans=0;
	memset(st,0,sizeof(st));
	cin>>x>>y;
	dfs(x,0,0);
	cout<<zbw+w[x]+w[y]<<endl;
}

int main(){
	fst
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			fl[i][a[i][j]]=1;
		}
	}
	while(q--){
		solve();
	}
	return 0;
}
//CCF=chinese can fly 
/*
Oct31==Dec25?

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
//ACACACACACACACACACACACACAC
/*
		//\\                   ==========          ==
	   //  \\                ==          ==        == 
	  //    \\             ===             =       ==
	 //      \\           ===                      ==
	//        \\          ===                      ==
   //==========\\         ===                      ==
  //            \\         ===
 //              \\          ==          ==        ==
//                \\            ==========         ==




*/
