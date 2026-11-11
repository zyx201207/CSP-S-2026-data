#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,M=5e5+10,D=20;
int c,n,m,d,q,k,target,consume;
int st,ed,cur,go;
int ground[M];//每个地铁站从地铁口到站厅 
int nst[M+N];
ll dist[M+N];
ll under,ans;
int nside=0;
bool inqu[M+N];
struct bian{
	int from;
	int to;
	int nxt;
	int w;
}b[M*D];
void add(int x,int y,int con){
	++nside;
	b[nside].from=x;
	b[nside].to=y;
	b[nside].w=con;
	b[nside].nxt=nst[x];
	nst[x]=nside;
//      ^
}
ll spfa(int st,int ed){
	memset(dist,0x3f,sizeof dist);
	memset(inqu,false,sizeof inqu);
	dist[st]=0;
	queue<int> qu;
	qu.push(st);
	inqu[st]=1;
	while(!qu.empty()){
		for(int i=nst[qu.front()];i;i=b[i].nxt){
			cur=b[i].from;
			go=b[i].to;
			consume=b[i].w;
			if(dist[cur]+consume<dist[go]){
				dist[go]=dist[cur]+consume;
				if(!inqu[go]){
					qu.push(go);
				}
			}
		}inqu[qu.back()]=0;
		qu.pop();
	}return dist[ed];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>ground[i];
	}for(int i=1;i<=n;++i){//第i号线路 
		cin>>k;
		for(int j=1;j<=k;++j){
			cin>>target>>consume;
			//线路点=m+i 
			add(m+i,target,consume);
			add(target,m+i,consume);
		}
	}while(q--){
		cin>>st>>ed;
		under=spfa(st,ed);
		ans=under+ground[st]+ground[ed];
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
in1:
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
 
in2:
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


*/ 

/*
test network:
	for(int i=1;i<=m+n;++i){
		if(i>m) cout<<"(a)";
		cout<<"station "<<i<<" to : ";
		for(int j=nst[i];j;j=b[j].nxt){
			if(b[j].to>m) cout<<"(a)";
			cout<<b[j].to<<' ';
		}cout<<'\n';
	}
*/
