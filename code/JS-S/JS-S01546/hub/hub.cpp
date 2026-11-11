#include<bits/stdc++.h>
#define N 1000005
#define ll long long
#define ls(v) ((v)<<1)
#define rs(v) (((v)<<1)|1)
#define pa pair<int,int>
#define fi first
#define se second
using namespace std;
int d[N],n;
bool ok[N];
vector<int>v[N];
void dfs(int x,int y,int z){
	d[x]=min(d[x],z);
	for(auto vv:v[x])if(vv!=y){
		dfs(vv,x,z+1);
	}
}int k;
int ge(int x){
	int sum=0;
	for(int i=0;i<n;i++){d[i+1]=1e9;
		if((x>>i)&1)ok[i+1]=1,sum++;
		else ok[i+1]=0;
	}if(sum!=k)return (int)1e9;
	for(int i=1;i<=n;i++){
		for(auto vv:v[i])if(vv>i&&ok[vv]&&ok[i])sum--;
	}if(sum>2)return (int)1e9;
int mx=0;
for(int i=1;i<=n;i++)if(ok[i])dfs(i,0,0);
for(int i=1;i<=n;i++)mx=max(mx,d[i]);
	return mx;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		v[i].clear();
		//nt a,b;
		//scanf("%d%d",&a,&b);
		//v[a].push_back(b);
		//v[b].push_back(a);
	}
	for(int i=1;i<n;i++){
		//v[i].clear();
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}int ans=n;
	for(int i=0;i<(1<<n);i++)ans=min(ans,ge(i));
		printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)solve();
	return 0;
}