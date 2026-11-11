#include<bits/stdc++.h>
using namespace std;
struct ee{
	long long n,sum=0;
	short flag=0;
};
struct cmp{
	bool operator()(const ee a,ee b){
		return a.sum>b.sum;
	}
};
long long c,n,m,d,q,w[514514],a[514514];
vector<ee> lx[505],zd[514514];
long long djstl(long long x,long long y){
	bool vis[514514],vislx[505];
	memset(vis,false,sizeof(vis));
	memset(vislx,false,sizeof(vislx));
	ee kskbl;
	kskbl.n=x,kskbl.sum=0,kskbl.flag=0;
	priority_queue<ee, vector<ee>, cmp> p;
	while(!p.empty()) p.pop();
	p.push(kskbl);
	while(true){
		long long aaa=p.top().n,s=p.top().sum,flag=p.top().flag;
		p.pop();
		if(flag==0){
			if(aaa==y) return s;
			vis[aaa]=1;
			for(int i=0;i<zd[aaa].size();i++){
				if(vislx[zd[aaa][i].n]==0){
					ee kskbl;
					kskbl.n=zd[aaa][i].n,kskbl.sum=s+zd[aaa][i].sum,kskbl.flag=1;
					p.push(kskbl);
				}
			}
		}
		else{
			vislx[aaa]=1;
			for(int i=0;i<lx[aaa].size();i++){
				if(vis[lx[aaa][i].n]==0){
					ee kskbl;
					kskbl.n=lx[aaa][i].n,kskbl.sum=s+lx[aaa][i].sum,kskbl.flag=0;
					p.push(kskbl);
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		while(k--){
			long long u,w;
			cin>>u>>w;
			ee kskbl;
			kskbl.n=u,kskbl.sum=w,kskbl.flag=1;
			lx[i].push_back(kskbl);
			kskbl.n=i,kskbl.flag=0;
			zd[u].push_back(kskbl);
		}
	}
	while(q--){
		long long s,e;
		cin>>s>>e;
		cout<<djstl(s,e)+a[s]+a[e]<<'\n';
	}
	return 0;
}
