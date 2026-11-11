#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t,n,k,dep[N],id,lst=0,ans=1e18,depp[N],fa[N],ff[N],maxn[N],mmax[N];
vector<int>tree[N];
void init(){
	for(int i=1;i<=n;i++){
		tree[i].clear();maxn[i]=mmax[i]=0;
	}
}
void dfs(int x,int f){
	dep[x]=dep[f]+1;fa[x]=f;
	if(dep[x]>dep[id])id=x;
	maxn[x]=dep[x]-1;mmax[x]=0;
	for(int i=0;i<tree[x].size();i++){
		int y=tree[x][i];
		if(y==f)continue;
		dfs(y,x);
		if(maxn[y]>=maxn[x]){
			mmax[x]=maxn[x];
			maxn[x]=maxn[y];
		}
		else if(maxn[y]>=mmax[x]){
			mmax[x]=maxn[y];
		}
		else if(mmax[y]>=mmax[x]){
			mmax[x]=mmax[y];
		}
	}
}
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==7){
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				tree[u].push_back(v);
				tree[v].push_back(u);
			}
			ans=1e18;
			for(int i=1;i<=n;i++){
				dfs(i,0);
				ans=min(ans,max((maxn[i]-2*mmax[i]+1)/2,mmax[i]));
			}
			cout<<ans<<endl;
			init();
		}
		return 0;
	}
	if(c==11||c==12||!c){
//		cout<<"fuck"<<endl;
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				tree[u].push_back(v);
				tree[v].push_back(u);
			}
			ans=1e18;
			id=0;
			dfs(1,0);
			dfs(id,0);
			lst=id;
			for(int i=1;i<=n;i++)ff[i]=fa[i],depp[i]=dep[i];
			for(int i=lst;i;i=ff[i]){
				if(abs(2*depp[i]-depp[lst])<=10){
//				cout<<"i"<<endl;
					dfs(i,0);
					
					ans=min(ans,max((maxn[i]-2*mmax[i]+1)/2,mmax[i]));
				}
			}
			cout<<ans<<endl;
			init();
		}
		return 0;
	}
	
	return 0;
}
//0 4
//7 2
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
