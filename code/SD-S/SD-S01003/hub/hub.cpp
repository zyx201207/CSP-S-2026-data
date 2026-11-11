#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<int> a[100100];
int vis[100100];
int n,k,ans,sum,c,t;
void dfs(int x){
	vis[x]=0;
	for(int i=0;i<a[x].size();i++)if(vis[a[x][i]])dfs(a[x][i]);
}
int dfss(int x,int fa,int ss,int fl){
	int mn=1e9;
	if(ss&(1<<(x-1)))fl=mn=0;
	for(int i=0;i<a[x].size();i++){
		int v=a[x][i];
		if(v==fa)continue;
		mn=min(mn,dfss(v,x,ss,(fl==-1?-1:fl+1))+1);
	}
	sum=max(sum,min((fl==-1?int(1e9):fl),mn));
	return mn;
}
void solve(){
	ans=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++)a[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	if(n<=20){
		for(int i=0;i<(1<<n);i++){
			int cnt=0,res=0;
			for(int j=1;j<=n;j++)vis[j]=bool(i&(1<<(j-1))),res+=bool(i&(1<<(j-1)));
			if(res!=k)continue;
			for(int j=1;j<=n;j++)if(vis[j])dfs(j),cnt++;
			if(cnt>2)continue;
			sum=0;
			dfss(1,0,i,-1);
			ans=min(ans,sum);
		}
		cout<<ans<<'\n';
		return;
	}
	int m=n/2;
	if(k==n){cout<<"0\n";return;}
	cout<<max((m-k+1)/3,1)<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
