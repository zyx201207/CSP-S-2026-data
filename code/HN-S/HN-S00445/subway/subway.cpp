#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5,M=50;
vector<pair<int,int>>g[N];
int w[M];
int k[N];
void add(int x,int y,int z){
	g[x].push_back({y,z});
	g[y].push_back({x,z});
}
int dis[N],vis[N];

void dij(int x){
    fill(dis,dis+N,1e18);
    fill(vis,vis+N,0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,x});
    dis[x]=0;
    while(pq.size()){
        int d=pq.top().first,x=pq.top().second;
        pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(auto nxt:g[x]){
            int y=nxt.first,w=nxt.second;
            if(dis[x]+w<dis[y]){
                dis[y]=d+w;
                pq.push({dis[y],y});
            }
        }
    }
}
void bfs(int x){
	
    fill(dis,dis+N,0);
    fill(vis,vis+N,0);
	queue<int>pq;
    pq.push(x);
    dis[x]=0;
    while(pq.size()){
        int x=pq.front();
        pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(auto nxt:g[x]){
            int y=nxt.first,w=nxt.second;
            dis[y]=dis[x]+w;
            pq.push(y); 
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			//cout<<"*"<<a[i][j]<<" -> #"<<i<<" "<<t[i][j]<<endl;
			add(a,m+i,t);
		}
	}
	//floyd(n+m);
	while(q--){
		int x,y;
		cin>>x>>y;
        if(x==y){
		cout<<0<<endl;continue;}
		if(c>=12 and c<=15){
			bfs(x);
		}
		else{
 		    dij(x);
		}
//		cerr<<dis[y]<<endl;
        cout<<dis[y]+w[y]+w[x]<<endl;
        /*
        if(x==y)cout<<0<<endl;
        else
        cout<<w[y]+w[x]<<endl;
        */
	}
    return 0;
}

/*
为什么答案会错啊！！！！！！！！ 

0 15 136 20 200
31 76 70 17 48 78 61 81 75 9 78 2 61 34 71 30 25 92 61 70 71 61 51 82 20 30 82 20 67 50 95 2 86 100 9 21 98 76 6 39 100 4 35 61 77 93 50 92 55 51 94 74 57 18 47 13 5 18 64 28 34 87 56 100 81 39 54 65 50 74 45 69 75 53 75 30 44 88 4 36 78 86 90 21 90 42 70 74 73 14 92 84 28 82 74 35 37 16 9 62 82 62 12 45 9 53 20 3 38 55 99 54 16 6 78 79 98 6 49 92 76 43 71 36 65 31 5 40 1 10 14 77 69 5 26 53
10 1 38 2 79 3 34 4 20 5 89 6 6 7 44 8 41 9 47 10 18
10 10 49 11 49 12 59 13 67 14 50 15 83 16 77 17 88 18 72 19 14
10 19 80 20 65 21 35 22 56 23 82 24 93 25 92 26 31 27 39 28 56
10 28 34 29 67 30 39 31 71 32 44 33 2 34 54 35 75 36 41 37 3
10 37 49 38 79 39 76 40 81 41 18 42 8 43 82 44 81 45 43 46 60
10 46 46 47 87 48 46 49 78 50 91 51 36 52 95 53 63 54 3 55 76
10 55 8 56 87 57 3 58 48 59 33 60 81 61 59 62 39 63 76 64 77
10 64 41 65 23 66 47 67 24 68 41 69 98 70 48 71 77 72 34 73 39
10 73 49 74 14 75 99 76 4 77 73 78 88 79 95 80 17 81 40 82 65
10 82 29 83 84 84 35 85 31 86 42 87 24 88 87 89 56 90 84 91 90
10 91 13 92 14 93 77 94 42 95 43 96 87 97 29 98 57 99 22 100 11
10 100 44 101 95 102 84 103 28 104 73 105 58 106 35 107 29 108 16 109 5
10 109 68 110 25 111 41 112 74 113 24 114 36 115 44 116 83 117 11 118 80
10 118 45 119 76 120 17 121 54 122 38 123 67 124 35 125 60 126 45 127 82
10 127 54 128 38 129 54 130 73 131 53 132 5 133 53 134 20 135 26 136 1
112 57

35
667
*/
