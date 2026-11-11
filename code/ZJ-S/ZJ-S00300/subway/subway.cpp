#include<bits/stdc++.h>
using namespace std;
const long long maxn=500;
const long long maxm=5e5;
long long c,n,m,d,Q;
long long w[maxm+1];
long long x,y;
set<long long>id[maxm+1];
//long long t[maxm+1][maxn+1];
set<long long>subway[maxn+1];
set<long long>::iterator it;
set<long long>::iterator it2;
bool vis[maxm+1];
//long long dis[maxm+1];
map<pair<long long,long long>,long long>t;
struct node{
	long long s_id;
	long long now,sum,id;
	friend bool operator<(node X,node Y){
		return (X.sum+t[make_pair(x,X.s_id)])>(Y.sum+t[make_pair(y,Y.id)]);
	}
};
priority_queue<node>q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
srand(time(0));
cin>>c>>n>>m>>d>>Q;
for(int i=1;i<=m;i++){
	cin>>w[i];
}
for(int i=1;i<=n;i++){
	long long k;
	cin>>k;
	for(int j=1;j<=k;j++){
		long long a,T;
		cin>>a>>T;
		subway[i].insert(a);
		id[a].insert(i);
		//t[a][i]=T;
		t[make_pair(a,i)]=T;
	}
}
for(int i=1;i<=Q;i++){
	cin>>x>>y;
	while(!q.empty())q.pop();
	memset(vis,false,sizeof(vis));
	for(it2=id[x].begin();it2!=id[x].end();it2++){
	node U;
	U.now=x;
	U.sum=0;
	U.id=*it2;U.s_id=U.id;
	q.push(U);}
	while(!q.empty()){
		node now;
		now=q.top();
		q.pop();
		if(vis[now.now]==true)continue;
		vis[now.now]=true;
		if(now.now==y){
cout<<t[make_pair(x,now.s_id)]+t[make_pair(y,now.id)]+now.sum+w[x]+w[y]<<endl;
		//	cout<<now.now<<" "<<now.sum<<" "<<now.s_id<<" "<<now.id<<"AC\n";
			break;
		}
	//	cout<<now.now<<" "<<now.sum<<"!\n";
		for(it2=id[now.now].begin();it2!=id[now.now].end();it2++){
			//bian li subway
			long long now_subway=*it2;
			for(it=subway[now_subway].begin();it!=subway[now_subway].end();it++){
			if(now_subway==now.id){
			node I;
			I.now=*it;
			I.sum=now.sum;
			I.id=now_subway;
			I.s_id=now.s_id;
			q.push(I);}
			else{
				node OP;
				OP.id=now_subway;
				OP.now=*it;
				OP.s_id=now.s_id;
				OP.sum=now.sum+t[make_pair(now.now,now.id)]+t[make_pair(now.now,now_subway)];
				q.push(OP);
			}
				//cout<<<<" ";
			}//cout<<"!\n";
		}
	}
}
return 0;}
