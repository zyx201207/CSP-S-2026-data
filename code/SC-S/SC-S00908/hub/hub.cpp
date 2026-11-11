#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+10;
int c,t,n,k,root[maxn],ans;
vector<int> e[maxn];
bool vis[maxn];
int dfs(int x,int deep,bool re){
	int ans=1;
	vis[x]=1;
	if(deep==1){if(re)vis[x]=0;return ans;}
	for(const auto &a:e[x]){
		if(vis[a])continue;
		ans+=dfs(a,deep-1,re);
	}
	if(re)vis[x]=0;
	return ans;
}
void read(){
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		int l=1,r=k;
		while(l<r){
			int mid=(l+r)>>1;
			int maa=0;
			for(int i=1;i<=n;i++){
				int temp=dfs(i,mid,0);
				for(int j=1;j<i;j++){
					maa=max(temp+dfs(j,mid,1),maa);
				}
				dfs(i,mid,1);
			}
			if(maa<k){
				l=mid+1;
			}else{
				r=mid;
				ans=mid;
			}
		}
		cout<<r<<'\n';
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	read();
	
	return 0;
}