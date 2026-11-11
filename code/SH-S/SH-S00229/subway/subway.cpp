#include<bits/stdc++.h>
using namespace std;
int w[500010],a[510][510],t[510][510],s[5010][5010];
long long dis[500010];
bool book[500010];

int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
void dj(int x,int y){
	memset(dis,0x3f,sizeof dis); dis[x]=0;
	for(int i=1;i<=m;i++) dis[i]=s[x][i];
	memset(book,0,sizeof book); book[x]=1;
	
	for(int i=1;i<=m;i++){
		int u=0,mins=INT_MAX;
		for(int j=1;j<=m;j++){
			if(!book[j] && dis[j]<mins){
				mins=dis[j];
				u=j;
			}
		}
		book[u]=1;
		for(int v=1;v<=m;v++){
			if(dis[u]+s[u][v]<dis[v]){
				dis[v]=dis[u]+s[u][v];
			}
		}
	}
//	q.push(x);
//	
//	while(!q.empty()){
//		int u=q.front(),mins=INT_MAX,v;
//		q.pop();
//		for(int i=1;i<=n;i++){
//			if(!book[i] && s[u][i]){
//				mins=dis[i];
//				v=i;
//			}
//		}
//		book[v]=1;
//		
//	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(s,0x3f,sizeof s);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) s[i][i]=0;
	
	for(int i=1;i<=m;i++) cin>>w[i]; 
	for(int i=1;i<=n;i++){
		int p;
		cin>>p;
		for(int j=1;j<=p;j++){
			cin>>a[i][j]>>t[i][j];
		}
		if(p==2) s[a[i][1]][a[i][2]]=t[i][1]+t[i][2],s[a[i][2]][a[i][1]]=t[i][1]+t[i][2];
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		dj(x,y);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	
	return 0;
}
