#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long long a[500005],mp[5005][5005],b[5005][5005];
vector<long long>v[502];
bool vi[500005][502],vis[5005][5005];
struct node{
	long long p,pre;
};
long long n,c,m,d,q;
void bfs(long s,long e){
	queue<node>q;
	node no;
	no.p=s;
	no.pre=0;
	q.push(no);
	while(q.size()){
		long long x=q.front().p;
		long long pre=q.front().pre;
		q.pop();
		for(int i=1;i<=n;i++){
			if(vi[x][i]){//站台到线路 
				for(int j=0;j<v[i].size();j++){//线路到站台
					if(vis[x][v[i][j]])continue; 
					mp[x][v[i][j]]=b[x][i]+b[v[i][j]][i]+mp[pre][x];
					vis[x][v[i][j]]=1;
					node t;
					t.p=v[i][j];
					t.pre=x;
					q.push(t);
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","w",stdin);
	freopen("subway.out","r",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		long long x;
		cin>>x;
		v[i].push_back(x);
		vi[x][i]=1;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			b[v[i][a]][i]=t;
		}
	}
	while(q--){
		long long s,e;
		cin>>s>>e;
		bfs(s,e);
		cout<<mp[s][e]+a[s]+a[e]<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}