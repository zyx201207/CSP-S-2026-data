#include<bits/stdc++.h>
using namespace std;
struct sd{
	long long id,val;
};
long long c,n,m,d_,q_,a[2005],t[2005][2005],k[2005],d[2005],tot,cnt[500005][5],b[500005],t1[5][500005],tt=1e18;
vector <long long> road[2005];
vector <sd> e[2005];
priority_queue <pair<long long,long long> > q;
void dij(long long start){
	while(q.size()) q.pop();
	for(long long i=1;i<=tot;++i) d[i]=1e18;
	d[start]=0;
	q.push({0,start});
	while(q.size()){
		long long u=q.top().second,l=q.top().first;
		q.pop();
		if(d[u]!=-l) continue;
		for(auto v:e[u]){
			//cout<<u<<' '<<v.id<<' '<<v.val<<endl;
			if(d[v.id]>d[u]+v.val){
				d[v.id]=d[u]+v.val;
				q.push({-d[v.id],v.id});
			}
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d_,&q_);
	tot=m;
	for(long long i=1;i<=m;++i) scanf("%lld",&a[i]);
	if(n==1){
		for(long long i=1;i<=n;++i){
			scanf("%lld",&k[i]);
			for(long long j=1;j<=k[i];++j){
				long long x;
				scanf("%lld",&x);
				scanf("%lld",&t1[i][x]);
			}
		}
		for(long long i=1;i<=q_;++i){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",a[x]+a[y]+t1[1][x]+t1[1][y]);
		}
		return 0;
	}
	if(n==2){
		for(long long i=1;i<=n;++i){
			scanf("%lld",&k[i]);
			for(long long j=1;j<=k[i];++j){
				long long x;
				scanf("%lld",&x);
				scanf("%lld",&t1[i][x]);
				cnt[x][i]=1;
				b[x]+=t1[i][x];
			}
		}
		for(long long i=1;i<=m;++i){
			if(cnt[i][1] && cnt[i][2]){
				tt=min(tt,b[i]);
			}
		}
		for(long long i=1;i<=q_;++i){
			long long x,y,d1=1e18,d2=1e18;
			scanf("%lld%lld",&x,&y);
			if(cnt[x][1] && cnt[y][1]) d1=t1[1][x]+t1[1][y];
			if(cnt[x][2] && cnt[y][2]) d1=t1[2][x]+t1[2][y];
			//cout<<d1<<' '<<tt<<endl;
			if(d1!=1e18 || d2!=1e18){
				printf("%lld\n",min(d1,d2)+a[x]+a[y]);
			}else{
				if(cnt[x][1]){
					printf("%lld\n",a[x]+a[y]+tt+t1[1][x]+t1[2][y]);
				}else{
				printf("%lld\n",a[x]+a[y]+tt+t1[2][x]+t1[1][y]);
				}
			}
		}
		return 0;
	}
	for(long long i=1;i<=n;++i){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];++j){
			long long x;
			scanf("%lld%lld",&x,&t[i][j-1]);
			road[i].push_back(x);
		}
	}
	for(long long i=1;i<=n;++i){
		for(long long j=0;j<k[i];++j){
			tot++;
			for(long long z=0;z<k[i];z++){
				//cout<<road[i][z]<<endl;
				e[tot].push_back({road[i][z],t[i][z]});
				e[road[i][z]].push_back({tot,t[i][z]});
			}
		}
	}
	for(long long i=1;i<=q_;++i){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		dij(x);
		printf("%lld\n",d[y]+a[x]+a[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/