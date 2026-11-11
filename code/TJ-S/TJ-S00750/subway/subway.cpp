#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int base_size= 500005;

int c,n,m,d,q;
int w[base_size];
bool finish[base_size+500];

int fa[base_size+500];

struct edge{
	vector<int> to;
	vector<int> size;
}e[base_size+500];

void dijkstra(int start,int end){
	int dist[base_size+500];
	memset(dist,INF,sizeof dist);
	memset(finish,0,sizeof finish);
	for(int i = 0;i < e[start].size.size();i++){
		dist[e[start].to[i]] = e[start].size[i];
		//cout<<"wehave"<<e[start].to[i]<<"in"<<e[start].size[i]<<endl;
	}
	finish[start] = 1;
	for(int oo = 1;oo < n+m;oo++){
		int nxt=-1;
		for(int j = 0;j < m;j++){
			if(nxt == -1){
				if(!finish[j]) nxt = j;
				else continue;
			}
			if(dist[j]<dist[nxt] && !finish[j]) nxt = j;
		}
		for(int i = base_size;i < base_size+n;i++){
			if(nxt == -1){
				if(!finish[i]) nxt = i;
				else continue;
			}
			if(dist[i]<dist[nxt] && !finish[i]) nxt = i;
		}
		/*cout<<"new node!"<<nxt<<endl;
		cout<<"========================"<<endl;
		for(int i = 0;i < e[nxt].size.size();i++){
			
			cout<<e[nxt].to[i]<<" "<<e[nxt].size[i]<<endl;
			
		}
		cout<<"========================"<<endl;*/
		
		for(int i = 0;i < e[nxt].size.size();i++){
			//cout<<"fs node:"<<(e[nxt].to[i])<<" "<<dist[nxt]<<":"<<e[nxt].size[i]<<endl;
			if((dist[nxt]+e[nxt].size[i] <= dist[e[nxt].to[i]]) && !finish[e[nxt].to[i]]){
				dist[e[nxt].to[i]] = dist[nxt]+e[nxt].size[i];
				//cout<<nxt<<"to"<<e[nxt].to[i]<<"new!!"<<dist[e[nxt].to[i]]<<endl;
			}
		}
		finish[nxt] = 1;
	}
	printf("%d\n",(dist[end]+w[start]+w[end]));
	//cout<<(dist[end]+w[start]+w[end])<<endl;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	//cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		scanf("%d",&w[i]);
		//cin>>w[i];
	}
	
	for(int i = 0;i < n;i++){
		int k;
		scanf("%d",&k);
		//cin>>k;
		for(int j = 0;j < k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			//cin>>a>>t;
			//cout<<"input:"<<a<<" "<<t<<"to"<<base_size+i<<endl;
			e[a].to.push_back(base_size+i);
			e[a].size.push_back(t);
			e[base_size+i].to.push_back(a);
			e[base_size+i].size.push_back(t);
		}
	}
	for(int i = 0;i < q;i++){
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		//cin>>xx>>yy;
		dijkstra(xx,yy);
	}
	
	
	return 0;
} 
