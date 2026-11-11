#include<bits/stdc++.h>
using namespace std;
//Nya~ 
typedef long long bint;
bint c,n,m,d,q;
bint w[500005];
struct subway{
	private:
		vector<bint> stations;
		unordered_map<bint,bint> times;
		bool lock;
	public:
		inline void locking(bool l){
			lock=l;
			return;
		}
		inline void add_station(bint a,bint t){
			if(lock){
				return;
			}
			stations.push_back(a);
			times[a]=t;
		}
		inline bool find_station(bint a){
			return times.count(a)!=0;
		}
		inline bint far(bint a){
			if(times.count(a)==0){
				return 0x3f3f3f3f;
			}
			return times[a];
		}
}sw[505];
bint edge[505][505],distanc[505][505];
inline void update(){
	for(bint s=1;s<=m;s++){
		vector<bint> cdk;
		for(bint sl1=1;sl1<=n;sl1++){
			if(sw[sl1].find_station(s)){
				cdk.push_back(sl1);
			}
		}
		for(bint i:cdk){
			for(bint j:cdk)if(j!=i){
				edge[i][j]=min(edge[i][j],sw[i].far(s)+sw[j].far(s));
			}
		}
	}
}
bool met[505];
inline void bs(bint root){
	priority_queue<pair<bint,bint>,vector<pair<bint,bint>>,greater<pair<bint,bint>>> que;
	memset(met,0,sizeof(met));
	que.push({0,root});
	while(!que.empty()){
		pair<bint,bint> p=que.top();
		que.pop();
		bint u=p.second;
		if(met[u]){
			continue;
		}
		met[u]=1;
		distanc[root][u]=p.first;
		for(bint v=1;v<=n;v++)if(!met[v]&&edge[u][v]!=0x3f3f3f3f){
			que.push({distanc[root][u]+edge[u][v],v});
		}
	}
}
inline void wayway(){
	for(bint i=1;i<=n;i++){
		bs(i);
	}
}
inline bint getans(bint x,bint y){
	vector<bint> cdk1,cdk2;
	for(bint sl1=1;sl1<=n;sl1++){
		if(sw[sl1].find_station(x)){
			cdk1.push_back(sl1);
		}
		if(sw[sl1].find_station(y)){
			cdk2.push_back(sl1);
		}
	}
	bint ans=0x3f3f3f3f;
	for(bint i:cdk1){
		for(bint j:cdk2){
			ans=min(ans,distanc[i][j]+sw[i].far(x)+sw[j].far(y));
		}
	}
	return ans+w[x]+w[y];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(edge,0x3f,sizeof(edge));
	for(bint i=1;i<=m;i++){
		cin>>w[i];
	}
	for(bint i=1;i<=n;i++){
		bint k,a,t; 
		cin>>k;
		for(bint j=1;j<=k;j++){
			cin>>a>>t;
			sw[i].add_station(a,t);
		}
		sw[i].locking(1);
	}
	update();
	wayway();
	for(bint i=1;i<=q;i++){
		bint x,y;
		cin>>x>>y;
		cout<<getans(x,y)<<'\n';
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

