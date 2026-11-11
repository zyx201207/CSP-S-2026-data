#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1e3;
int n,m,id,c,d,q,as[20100][550];
vector<pair<int,int>>ne[N];
int read(){
	char ch=getchar();
	int re=0,k=1;
	while('0'>ch||ch>'9'){
		if(ch=='-')k=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		re=re*10+(ch-'0');
		ch=getchar();
	}
	return re*k;
}
void add(int x,int y,int z){
	ne[x].push_back({y,z});
	ne[y].push_back({x,z});
}
bool bl[N];
int len[N];
void dijstra(int a){
	priority_queue<pair<int,int>>q;
	q.push({0,a});
	for(int i=0;i<=id;i++){
		bl[i]=0;
	}
	while(!q.empty()){
		pair<int,int>p=q.top();
		q.pop();
		int w=p.first,u=p.second;
		if(!bl[u])len[u]=0-w,bl[u]=1;
		for(pair<int,int>i:ne[u]){
			int v=i.first,we=i.second;
			if(!bl[v]){
				q.push({w-we,v});
			}
		}
	}
	for(int i=1;i<=m;i++){
		as[i][a]=len[i];
//		cout<<len[i]<<" ";
	}
//	cout<<endl;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	id=m+1;
	for(int i=1;i<=m;i++){
		int s=read();
		add(i,id,s);
		id++;
	}
	for(int i=1;i<=n;i++){
		int k=read();
		while(k--){
			int a=read(),b=read();
			add(a+m,id,b);
		}
		id++;
	}
	for(int i=m*2+1;i<id;i++){
		dijstra(i);
	}
	while(q--){
		int x=read(),y=read();
		int ans=LLONG_MAX;
		for(int i=1;i<=n;i++){
			ans=min(ans,as[x][i+m*2]+as[y][i+m*2]);
//			cout<<i+m*2<<' '<<as[x][i+m*2]<<" "<<as[y][i+m*2]<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}