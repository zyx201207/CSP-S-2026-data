#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=N*2;
long long ww[N];
map<int,long long> ss[N];
int h[N],e[M],ne[M],w[M],idx=1;
int st[N];
void add(int a,int b,int c){
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int>>> q;
void dijk(int u){
	map<int,long long> d;
	q.push({0,u});
	while(q.size()){
		auto t=q.top();
		q.pop();
		long long x=t.second,y=t.first;
		for(int i=h[x];i;i=ne[i]){
			int j=e[i];
			if((d[j]==0&&j!=u)||d[j]>y+w[i]){
				d[j]=y+w[i];
				q.push({d[j],j});
			}
		}
	}
	ss[u]=d;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ww[i];
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,s;
			scanf("%d%d",&a,&s);
			add(a,i+m,s);
			add(i+m,a,s);
		}
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		if(st[a])printf("%lld\n",ss[a][b]+ww[a]+ww[b]);
		else if(st[b])printf("%lld\n",ss[b][a]+ww[a]+ww[b]);
		else{
			dijk(a);
			st[a]=1;
			printf("%lld\n",ss[a][b]+ww[a]+ww[b]);
		}
	}
	return 0;
} 
