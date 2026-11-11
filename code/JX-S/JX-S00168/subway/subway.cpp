#include<bits/stdc++.h>
using namespace std;
struct node{
	long long s,e,q;
	bool operator>(node b){
		return q>b.q;
	}
};
long long c,n,m,d,q,w[500005],j[500005];
bool vis[500005];
vector<long long>a[500005],t[500005];
vector<node>tu[500005];
priority_queue<node,vector<node> >dq;
bool cmp(node a,node b){
	return a.q<b.q;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			long long a1,t1;
			scanf("%lld %lld",&a1,&t1);
			a[i].push_back(a1);
			t[i].push_back(t1);
			for(int k=1;k<j;k++){
				node ma;
				ma.e=a1;
				ma.q=t1;
				tu[a[i][k]].push_back(ma);
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long x,y;
		scanf("%lld %lld",&x,&y);
		j[x]=0;
		vis[x]=1;
		for(unsigned long int j=0;j<t[x].size();j++){
			node mb;
			mb.s=x;
			mb.e=tu[x][j].e;
			mb.q=tu[x][j].q+w[x];
			dq.push(mb);
		}
		while(!dq.empty()){
			node ma;
			ma=dq.top();
			dq.pop();
			j[ma.e]=j[ma.s]+tu[ma.s][ma.e].q;
			vis[ma.e]=1;
			if(ma.e==y){
				break;
			}
			for(unsigned long int j=0;j<tu[ma.e].size();j++){
				if(!vis[j]){
					node na;
					na.s=ma.e;
					na.e=j;
					na.q=tu[ma.e][j].q+tu[ma.s][ma.e].q;
					dq.push(na);
				}
			}
		}
		printf("%lld\n",j[y]);
	}
	return 0;
}
