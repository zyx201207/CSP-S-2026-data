#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
struct node{
	long long to;
	long long length;
};
vector<node> map[505];
long long c,n,m,d,q;
long long visit[505];
long long len[505];
long long minl(long long start,long long end){
	queue<long long> q;
	q.push(start);
	while(!q.empty()){
		long long t=q.front();
		q.pop();
		for(long long i=0;i<map[t].size();i++){
			if(len[t]+map[t][i].length<len[map[t][i].to]){
				q.push(map[t][i].to);
				len[map[t][i].to]=len[t]+map[t][i].length;
			}
		}
	}
	return len[end];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		long long w;
		cin>>w;
		map[i].push_back({i+m,w});
		map[i+m].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		long long path[505];
		long long value[505];
		for(int j=1;j<=k;j++){
			cin>>path[j]>>value[j];
		}
		for(int a=1;a<=k;a++){
			for(int b=a+1;b<=k;b++){
				map[path[a]+m].push_back({path[b]+m,value[a]+value[b]});
				map[path[b]+m].push_back({path[a]+m,value[a]+value[b]});
			}
		}
	}
	while(q--){
		long long x,y;
		cin>>x>>y;
		for(int i=1;i<505;i++){
			visit[i]=0;
			len[i]=LONG_LONG_MAX;
		}
		len[x]=0;
		cout<<minl(x,y)<<endl;
	}
	return 0;
}
