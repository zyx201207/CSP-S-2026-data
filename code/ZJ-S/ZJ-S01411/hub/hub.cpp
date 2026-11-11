#include <bits/stdc++.h>
using namespace std;
const int N=1e3;
int xx[N];
long long c,t,n,k,head[N],u,v,cnt=0,tt[N],ans=LONG_LONG_MAX,z[N];
struct node{
	long long nxt,to;
}edge[N];
queue <long long > qu;
void add(long long x,long long y){
	edge[++cnt].to=y;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
void dfs(long long x,long long fa){
	if(x==fa) return;
	for(int i=head[x];i;i=edge[i].nxt){
		if(edge[i].to==fa) continue;
		long long to=edge[i].to;
		if((tt[to]==0)&&(xx[to]==1)){
			tt[to]=1;
			dfs(to,x);
		}
	}
}
bool check(long long n){
	long long sum=0;
	for(int i=1;i<=n;i++) tt[i]=0;
	for(int i=1;i<=n;i++){
		if((tt[i]==0)&&(xx[i]==1)){
			tt[i]=1;
			dfs(i,0);
			sum++;
		}
	}
	if(sum>2) return false;
	return true;
}
long long fish_egg(long long x){
	while(!qu.empty()) qu.pop();
	for(int i=1;i<=n;i++){
		z[i]=LONG_LONG_MAX;
		if(xx[i]==1){
			z[i]=0;
			qu.push(i);
		}
	}
	while(!qu.empty()){
//		cout<<"fish_egg"<<endl;
		long long tp=qu.front();
//		cout<<"fish_egg"<<" "<<tp<<endl;
		qu.pop();
		for(int i=head[tp];i;i=edge[i].nxt){
//			cout<<"fish_egg"<<endl;
			if(z[edge[i].to]>z[tp]+1){
//				cout<<"fish_egg"<<endl;
				z[edge[i].to]=z[tp]+1;
				qu.push(edge[i].to);
			}
		}
	}
	long long ma=0;
	for(int i=1;i<=n;i++) ma=max(ma,z[i]);
	return ma;
}
void dfss(long long x,long long kk){
	if(kk>k) return;
	if(x>n){
		if(k!=kk) return; 
		if(check(n)){
			long long ss=fish_egg(n);
			ans=min(ans,ss);
		}
		return;
	}
	xx[x]=1;
	dfss(x+1,kk+1);
	xx[x]=0;
	dfss(x+1,kk);
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=LONG_LONG_MAX;
		for(int i=1;i<=n;i++) head[i]=0;cnt=0;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		
		
		dfss(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
/*
5 5 
1 2 4 8 9
*/