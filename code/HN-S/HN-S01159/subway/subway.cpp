#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=2001;

ll read(){
	ll s=0,w=-1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9')
		s*=10,s+=ch-'0',ch=getchar();
	return s*w;
}

struct Node{
	int y,v;
	Node(int _y,int _v){
		y=_y,v=_v;
	} 
};
int c,n,m,d,q,x,y,k,w[N],dist[N][N],cnt;
priority_queue<pair<int,int>>que;
vector<Node>E[N];
bool b[N];

void Dijkstra(int s){
	memset(b,true,sizeof(b));que.push(make_pair(0,s));
	while(!que.empty()){
		int x=que.top().second;que.pop();
		for(auto i:E[x])
			if(dist[s][i.y]>dist[s][x]+i.v)
				dist[s][i.y]=dist[s][x]+i.v,que.push(make_pair(dist[s][i.y],i.y));
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q,cnt=m;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++)
		dist[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		++cnt,dist[cnt][cnt]=0;
		for(int j=1;j<=k;j++)
			cin>>x>>y,E[cnt].push_back(Node(x,y)),E[x].push_back(Node(cnt,y));
//		for(int j=1;j<=k;j++)
//			cin>>x>>y,E[cnt][x]=E[x][cnt]=y;
	}
	for(int i=1;i<=cnt;i++)
		Dijkstra(i);
//	for(int i=1;i<=cnt;i++){
//		for(int j=1;j<=cnt;j++)
//			cout<<E[i][j]<<' ';
//		cout<<endl;
//	}
//	for(int k=1;k<=cnt;k++)
//		for(int i=1;i<=cnt;i++)
//			for(int j=1;j<=cnt;j++)
//				if(E[i][k]<1<<30&&E[k][j]<1<<30)
//					E[i][j]=min(E[i][j],E[i][k]+E[k][j]);
	while(q--)
		cin>>x>>y,cout<<dist[x][y]+w[x]+w[y]<<endl;
}
