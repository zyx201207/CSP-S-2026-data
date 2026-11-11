#include<bits/stdc++.h>
using namespace std;
const int MAN=5e5+10;
vector<int> e[MAN];//存图 
vector<int> a[MAN];
vector<int> t[MAN];
vector<int> s[MAN];
int g[MAN];
int w[MAN],k[510];//w每个地铁站站厅到地铁口的时间，k第i条路线经过的地铁站数 
int ans=0;
int T=0;

int bfs(int step,int end,int sum,int past){
	if(step==end) return sum;
	for(int v=0;v<g[step];v++){//遍历经过这个地铁站的线路
		if(a[e[step][v]][s[step][e[step][v]]+1]!=past&&s[step][e[step][v]]+1<k[e[step][v]]) bfs(a[e[step][v]][s[step][e[step][v]]+1],end,sum+1,step);
		if(a[e[step][v]][s[step][e[step][v]]-1]!=past&&s[step][e[step][v]]-1>=0) bfs(a[e[step][v]][s[step][e[step][v]]-1],end,sum+1,step);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//c测试点编号，n地铁线路数，m地铁站数，d每个地铁站最多被几条路线经过，q出行计划 
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a1,t1;
			cin>>a1>>t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
			e[a1].push_back(i);
			g[a1]++;
			s[a1].push_back(j);
			if(i==1&&j==1) T=t1;
		}
	}
	while(q--){
		int start,end;
		ans=0;
		cin>>start>>end;
		ans=w[start]+w[end];//先加终点和起点地铁口到站厅的时间
		int cnt=bfs(start,end,0,0);
		ans+=(cnt*2*T);
		cout<<ans<<"\n";
	}


//0 1 3 1 2
//1 1 1
//3 1 1 2 1 3 1
//1 3
//1 2

	return 0;
}
