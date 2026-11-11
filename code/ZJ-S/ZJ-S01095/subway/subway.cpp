#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q,w[500005],a[500005],t[500005];
long long in[500005],dis[500005];
long long ans[100005];
struct qus{
	int x,y,id;
}qu[100005];
bool cmp(qus a,qus b){
	return a.x<b.x;
}
struct node{
    long long to,val;
};
vector<node> v[500005];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
		for(int i=1;i<=m;i++){
			cin>>w[i];
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>a[j]>>t[j];
			}
			for(int j=2;j<=k;j++){
				node nw;
				nw.to=a[j];
				nw.val=t[j-1]+t[j];
				v[a[j-1]].push_back(nw);
				nw.to=a[j-1];
				v[a[j]].push_back(nw);
			}
		}
		for(int i=1;i<=Q;i++){
			cin>>qu[i].x>>qu[i].y;
			qu[i].id=i;
		}
		sort(qu+1,qu+1+Q,cmp);
		for(int T=1;T<=Q;T++){
			if(qu[T].x!=qu[T-1].x){
				int x=qu[T].x,y=qu[T].y;
				for(int i=1;i<=m;i++){
					in[i]=0;
					dis[i]=1e16;
				}
				dis[x]=0;
				in[x]=1;
				q.push(make_pair(dis[x],x));
				while(q.size()){
					int u=q.top().second;
					q.pop();
					in[u]=0;
					for(int i=0;i<v[u].size();i++){
						int to=v[u][i].to;
						int val=v[u][i].val; 
						if(dis[u]+val<dis[to]){
							dis[to]=dis[u]+val;
							if(in[to]==0){
								in[to]=1;
								q.push(make_pair(dis[to],to));
							}
						}
					}	
				}
				ans[qu[T].id]=dis[y]+w[x]+w[y];
			}
			else{
				int x=qu[T].x,y=qu[T].y;
				ans[qu[T].id]=dis[y]+w[x]+w[y];
			}
		}
		for(int i=1;i<=Q;i++){
			cout<<ans[i]<<"\n";
		}
	return 0;
} 
