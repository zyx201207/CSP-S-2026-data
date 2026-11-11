#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
const int N=1005;
int c,n,m,d,q;
//n : 地铁线路数 
//m : 地铁站数  
//d : 每个地铁站最多被几条线路经过 
//q : 以及出行计划数 
int sub[N];//有 n 条地铁  
int cntsub[N];//第 i 条地铁经过几站
int a[N][N];//第 i 条地铁经过第 j 个地铁站 
int t[N][N];//第 j 个地铁站到第 i 个地铁站台的时间 
int tra[N];//有多少个travel 
int w[N];//从每个地铁站的地铁口走到站厅需要的时间 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>cntsub[i];
		for(int j=1;j<=cntsub[i];j++){
			cin>>a[i][j]>>t[i][j]; 
		}
	} 
	for(int i=1;i<=n;i++){
		cin>>tra[i];
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6 
3 2 3 3 4 5 7
1 3
1 2
*/