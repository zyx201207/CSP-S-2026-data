#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
struct Node{
	int x,t;
	bool operator<(const Node&A)const{
		return A.t<t;
	}
};
int a[N],dis[N],sum[N],f[N];
vector<int>g[N];
void dist(int x){
	queue<Node>qu;
	qu.push({x,0});
	while(qu.size()){
		Node now=qu.front();qu.pop();
		if(now.t>dis[now.x])continue;
		for(auto i:g[now.x]){
			int k=i;
			if(dis[k]>dis[now.x]+1){
				dis[k]=dis[now.x]+1;
				sum[k]=sum[now.x];
				qu.push({k,dis[k]});
			}
			else if(dis[k]==dis[now.x]+1)sum[k]+=sum[now.x];
		}
	}
}
void solve(){
	int n,d;
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n>=10000){
		printf("0\n");
		return ;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				g[i].push_back(j);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)sum[j]=0,dis[j]=INT_MAX;
		sum[i]=1;
		dis[i]=0;
		dist(i);
		for(int j=i+1;j<=n;j++){
			if(sum[j]==2){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%lld%lld",&c,&T);
	while(T--)solve();
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/
