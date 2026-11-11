#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
vector<pair<long long,long long>>edge[10000000];
long long c,n,m,d,q,k,temp3,temp2,temp1,xx,yy;
long long sh[10000000],a[10000000];
void f(long long x){
	memset(sh,0x3f,sizeof(sh));
	//cout<<sh[1];
	//memset(dst,0x3f,);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;//¾àÀë£¬±àºÅ 
	pq.push({0,x});
	sh[x]=0;
	while(!pq.empty()){
		auto xxx =pq.top();
		pq.pop();
		long long co=xxx.first,u=xxx.second;
		
		if(co>=sh[u])continue;
		
		for(auto yyy:edge[u]){
			long long v=yyy.first;
			long long lee=yyy.second;
			//cout<<"---------from"<<u<<"to"<<v<<" "<<sh[v]<<" "<<sh[u]<<" "<<dst[u][v]<<"---------\n";
			if(sh[v]>sh[u]+lee){
				sh[v]=sh[u]+lee;
				pq.push({sh[v],v});
			}
			
		}
	} 
}
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//cout<<"---";
	temp3=m+1;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	//cout<<"-----------------------------------------";
	for(long long i=0;i<n;i++){
		cin>>k;
		temp3++;
		for(long long j=0;j<k;j++){
			cin>>temp1>>temp2;
			
			edge[temp1].push_back({temp3,temp2});
			edge[temp3].push_back({temp1,temp2});
			//dst[temp1][temp3]=temp2;
			//dst[temp3][temp1]=temp2;
		}
		//cin>>a[i];
	}
	//cout<<"---";
	for(long long i=0;i<q;i++){
		cin>>xx>>yy;
		f(xx);
		cout<<sh[yy]+a[xx]+a[yy]<<"\n";
	}
	return 0;
}
// 0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
