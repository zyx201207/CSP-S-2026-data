#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500+10,M=2*N,inf=0x3f3f3f3f;
int C,T;
int n,k;
int idx,h[N],to[M],ne[M];
void add(int u,int v){
	idx++;
	to[idx]=v;
	ne[idx]=h[u];
	h[u]=idx;
}
void _init(){
	idx=0;
	for(int i=1;i<=n;i++){
		h[i]=0;
	}
}
int ct(int x){
	int res=0;
	while(x){
		x-=(x&(-x));
		res++;
	}
	return res;
}
int dis[N];
int b[N],vis[N];//i点有没有被选择。 i点有没有被dfs过。 
vector <int> q;
deque <int> bq;
void dfs(int u){
	for(int i=h[u];i;i=ne[i]){
		int v=to[i];
		if(b[v]&&!vis[v]){
			vis[v]=1;
			dfs(v);
		}
	}
}
int check(int st){ //检查是否合规 + 得到答案 
	while(q.size())	q.pop_back();//  初始化q 
	for(int i=0;i<n;i++){
		dis[i+1]=inf;           //初始化dis 
		b[i+1]=0;      
		vis[i+1]=0;              //初始化
		if((st>>i)&1){
			b[i+1]=1;
			dis[i+1]=0;
			q.push_back(i+1); 
		//	cout<<i+1<<endl;
		}
	}
	int cnt=0;
	for(auto u:q){
		if(!vis[u]){
			vis[u]=1;
			cnt++;
			dfs(u);
		}
	}
	if(cnt>2){
		return -1;
	}
	for(auto u:q)	bq.push_back(u);
	int ans=0;
	while(bq.size()){
		int u=bq.front();
		ans=max(ans,dis[u]);
		bq.pop_front();
		for(int i=h[u];i;i=ne[i]){
			int v=to[i];
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				bq.push_back(v);
			}
		}
	}
	return ans;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d %d",&C,&T);
	while(T--){
		
		
		scanf("%d %d",&n,&k);
		_init();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			add(u,v);
			add(v,u);
		}
		
		int trueans=inf;
		for(int st=0;st<(1<<n);st++){//    枚举 
			if(ct(st)!=k)	continue;
			int tmp=check(st);	
			if(tmp!=-1){
				trueans=min(trueans,tmp);
			}
			
		}
		
		printf("%d\n",trueans);
		
		
	}
	return 0;
} 
