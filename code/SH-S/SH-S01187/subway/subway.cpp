#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000020
#define endl "\n"
#define first F
#define second S
#define iscc ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int c,n,m,d,Q;//分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int dist[N],vist[N];
int W[N];//依次表示从每个地铁站的地铁口走到站厅需要的时间
vector<int> g[N];
queue<pair<int,int>> q;
int ty[N];
int a[600],t[600][600];//1：下一个点  2：类型 
int fin[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//system("fc test.out test.ans\n");]
	iscc
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	} 
	bool fl=1;
	for(int i=1;i<=n;i++){
		int v; cin>>v;
		for(int j=1;j<=v;j++){
			ty[j]=i;
			int ti;
			cin>>a[j]>>ti;
			fin[a[j]]++;
			ty[a[j]]=i;
			t[a[j]][i]=ti;
			if(j>1){
				g[j-1].push_back(j);
			}
		}
	}
	
	if(c>=7&&c<=11){
		int co=0;
		for(int i=1;i<=n;i++){
			if(fin[i]==n){
				co=i;
				break;
			}
		}
		
		while(Q--){
			int x,y;cin>>x>>y;
			if(x!=co&&y!=co){
				cout<<W[x]+t[x][ty[x]]+t[co][ty[x]]+t[co][ty[y]]+t[y][ty[y]]+W[y];
			}
			else if(x!=co&&y!=co&&ty[x]==ty[y]){
				cout<<W[x]+W[y]+t[x][ty[x]]+t[y][ty[y]]>>endl;
			}
			else if(x==co){
				cout<<W[x]+W[y]+t[x][ty[x]]+t[y][ty[y]]<<endl;
			}
			else if(y==co){
				cout<<W[x]+W[y]+t[x][ty[x]]+t[y][ty[x]]<<endl;
			} 
		}
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


10 2 3 2 1
2 5 5
2 1 2 2 3
2 1 4 3 3
2 3

18
*/

