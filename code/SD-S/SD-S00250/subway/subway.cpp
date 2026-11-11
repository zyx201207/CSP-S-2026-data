#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct ques{
	int l,r,a;
}q[100001];
bool cmp(ques a,ques b){
	if(a.l!=b.l){
		return a.l<b.l;
	}
	return a.r<b.r;
}
struct aa{
	int to,w;
};
int n,m,t,ans[500001],a[500001],k,n2,d[1000001],v[1000001];
vector<aa> g[1000001];
bool operator<(aa a,aa b){
	return a.w>b.w;
}
void dijkstra(int s){
	priority_queue<aa> pq;
	memset(v,0,sizeof(v));
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	pq.push({s,0});
	while(pq.size()){
		aa u=pq.top();
		pq.pop();
		if(v[u.to]){
			continue;
		}
		v[u.to]=1;
		for(auto v:g[u.to]){
			if(d[v.to]>u.w+v.w){
				d[v.to]=u.w+v.w;
				pq.push({v.to,d[v.to]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout);
	cin>>t;
	cin>>m>>n>>t;
	cin>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	n2=n+1;
	for(int i=0;i<m;i++){
		cin>>k;
		int x,y;
		cin>>x>>y;
		g[n2].push_back({x,y});
		g[x].push_back({n2,y});
		n2++;
		for(int j=1;j<k;j++){
			cin>>x>>y;
			g[x].push_back({n2,y});
			g[n2-1].push_back({n2,0});
			g[n2].push_back({n2-1,0});
			g[n2].push_back({x,y});
			n2++;
		}
	}
	for(int i=0;i<t;i++){
		cin>>q[i].l>>q[i].r;
		q[i].a=i;
	}
	sort(q,q+t,cmp);
	int last=0;
	for(int i=0;i<t;i++){
		if(q[i].l!=last){
			dijkstra(q[i].l);
			last=q[i].l;
		}
		ans[q[i].a]=a[q[i].l]+a[q[i].r]+d[q[i].r];
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
