#include<iostream>
#include<vector>
#define int long long
using namespace std;
int n,k,f[201000],u[201000],v[201000];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
int get(int x){
	int cnt=0;
	while(x){
		if(x&1)cnt++;
		x>>=1;
	}
	return cnt;
}
bool vis[201000];
vector<int>a[201000];
int tot,dep[401000],num[201000];
int st[401000][40],lg[401000];
void dfs1(int fa,int x){
	st[++tot][0]=x;
	num[x]=tot;
	for(auto y:a[x]){
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		dfs1(x,y);
		st[++tot][0]=x;
	}
}
int lca(int x,int y){
	x=num[x];y=num[y];
	if(x>y)swap(x,y);
	int len=(y-x+1);
	if(dep[st[x][lg[len]]]<dep[st[y-(1ll<<lg[len])+1][lg[len]]])return st[x][lg[len]];
	else return st[y-(1ll<<lg[len])+1][lg[len]];
}
int check(int x){
	int ans=0;
	for(int i=1;i<=n;i++){
		int res=1e18;
		for(int j=1;j<=n;j++){
			if(!(x&(1ll<<(j-1))))continue;
			int fa=lca(i,j);
			res=min(ans,dep[i]+dep[j]-2*dep[fa]);
		}
		ans=max(ans,res);
	}
	return ans;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)a[i].clear();
		for(int i=1;i<=tot;i++){
			num[i]=dep[i]=lg[i]=0;
			for(int j=1;j<=30;j++)st[i][j]=0;
		}
		tot=0;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			a[u[i]].push_back(v[i]);
			a[v[i]].push_back(u[i]);
		}
		dfs1(0,1);
		for(int i=2;i<=tot;i++)lg[i]=lg[i/2]+1;
		for(int j=1;j<=lg[tot];j++){
			for(int i=1;i+(1ll<<j)-1<=tot;i++){
				if(dep[st[i][j-1]]<dep[st[i+(1ll<<(j-1))-1][j-1]])st[i][j]=st[i][j-1];
				else st[i][j]=st[i+(1ll<<(j-1))-1][j-1];
			}
		}
//		for(int j=0;j<=lg[tot];j++){
//			for(int i=1;i+(1ll<<j)-1<=tot;i++){
//				cout<<i<<" "<<j<<" "<<st[i][j]<<endl;
//			}
//		}
		int ans=1e18;
		for(int i=0;i<(1ll<<n);i++){
			if(get(i)!=k)continue;
			for(int j=1;j<=n;j++)f[j]=j,vis[j]=0;
			for(int j=1;j<n;j++){
				if((i&(1ll<<(u[j]-1)))&&(i&(1ll<<(v[j]-1)))){
					int x=find(u[j]),y=find(v[j]);
					if(x!=y)f[x]=y;
				}
			}
			for(int j=1;j<=n;j++){
				f[j]=find(f[j]);
				vis[f[j]]=1;
			}
			int cnt=0;
			for(int j=1;j<=n;j++)cnt+=vis[j];
			if(cnt<=2)ans=min(ans,check(i));
//			cout<<i<<" "<<cnt<<endl;
//			cout<<check(i)<<endl;
		}
		cout<<ans<<endl;
	}
} 
