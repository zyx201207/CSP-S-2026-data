#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5,D=24;
struct A{
	int t,id;
};
int c;
int n,m,d,t;
int w[N],k[D][N],a[D][N];
bool pp[N];
long long ans=0x3f3f3f3f3f;
vector<A>qp[N];
void dfs(int s,int e,int li,long long sum){
	if(s==e){
		sum+=k[li][e];
		ans=min(ans,sum);
		return ;
	}
	for(auto o:qp[s]){
		if(!pp[o.t]){
			bool p=0;
			pp[o.t]=1;
			if(o.id!=li){
				p=1;
				sum+=(k[li][s]+k[o.id][s]);
			}
			dfs(o.t,e,o.id,sum);
			if(p) sum-=(k[li][s]+k[o.id][s]);
			pp[o.t]=0;
		}
	}
}
bool B=1;
void bfs(long long x,long long z){
	queue<A>q;
	q.push({x,0});
	while(q.size()){
		auto kk=q.front();
		q.pop();
		for(auto e:qp[kk.t]){
			if(!pp[e.t]){
				pp[e.t]=1;
				q.push({e.t,e.tp+kk.tp});
			}
			if(e.t==z){
				ans=min(kk.tp+e.t);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&t);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int l;
		if(l>2){
			B=0;
		}
		scanf("%d",&l);
		for(int j=1;j<=l;j++){
			scanf("%d",&a[i][j]);
			scanf("%d",&k[i][a[i][j]]);
			if(j!=1){
				if(B){
					qp[a[i][j-1]].push_back({a[i][j],k[i][a[i][j]]})
					qp[a[i][j]].push_back({a[i][j],k[i][a[i][j-1]]})
				}
				else{
					qp[a[i][j-1]].push_back({a[i][j],i});
					qp[a[i][j]].push_back({a[i][j-1],i});
				}
				
			}
		}
	}
	while(t--){
		int l,r;
		ans=0x3f3f3f3f3f;
		scanf("%d%d",&l,&r);
		if(B){
			bfs(l,r);	
		}
		else{
			dfs(l,r,0,0);
		}
		ans=ans+w[l]+w[r];
		cout<<ans<<endl;
	}
	return 0;
}