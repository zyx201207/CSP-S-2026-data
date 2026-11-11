#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000006];
int fa[1000006];
int dep[1000006];//这个是深度
int vis[1000006];
//int dep2[1000006];
void dfs(int now,int pre){
	//这个算dep用于求树的直径
	fa[now]=pre;
	dep[now]=dep[pre]+1;
	for(auto i:v[now]){
		if(i==pre) continue;
		dfs(i,now);
	}
}
int mx,my;
int n,x;
bool check(int cnt){
	for(int i=1;i<=n;i++) vis[i]=0;
	dfs(mx,0);
	int xa,wb;
	xa=my;
	for(int i=1;i<=cnt;i++) xa=fa[xa];
	wb=mx;
	
	dfs(my,0);
	for(int i=1;i<=cnt;i++) wb=fa[wb];
	//cout<<cnt<<" "<<xa<<" "<<wb<<"\n";
	dfs(xa,0);
	for(int i=1;i<=n;i++) if(dep[i]<=cnt+1) vis[i]=1;
	dfs(wb,0);
	for(int i=1;i<=n;i++) if(dep[i]<=cnt+1) vis[i]=1;
	for(int i=1;i<=n;i++) if(vis[i]==0) return 0;
	return 1;
}
struct dsu{
	int fa[20];
	void clear(){
		for(int i=1;i<20;i++) fa[i]=i;
	}
	int find(int x){
		if(fa[x]==x) return x;
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		x=find(x);y=find(y);fa[x]=y;
	}
} d; 
int v2[20];
int check2(){
	int t=0;
	d.clear();
	for(int i=1;i<=n;i++){
		t+=v2[i];
		if(v2[i]){
			for(auto j:v[i]){
				if(v2[j]) d.merge(i,j);
			}
		}
	}
	if(t!=x) return 0x3f3f3f3f;
	set<int>s;
	for(int i=1;i<=n;i++) if(v2[i])s.insert(d.find(i));
	if(s.size()>2) return 0x3f3f3f3f;
	memset(vis,0x3f,sizeof vis);
	for(int i=1;i<=n;i++){
		if(v2[i])dfs(i,0);
		for(int j=1;j<=n;j++){
			vis[j]=min(vis[j],dep[j]-1);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,vis[i]);
	return ans;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>x;
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<n;i++){
			int a,b;cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		if(x==2){
			dfs(1,0);
			int mn=0;
			for(int i=1;i<=n;i++){
				if(dep[i]>mn){
					mn=dep[i];
					mx=i;
				}
			}
			dfs(mx,0);
			mn=0;
			for(int i=1;i<=n;i++){
				if(dep[i]>mn){
					mn=dep[i];
					my=i;
				}
			}
			//mx-my为树的直径，长度为mn根为mx
			//以下是二分 
			int l=1,r=mn,mid,ans=0;
			while(l<=r){
				mid=(l+r)/2;
				if(check(mid)){
					r=mid-1;
					ans=mid;
				}
				else l=mid+1;
			}
			cout<<ans<<"\n";
		}
		else{
			//暴力 代码 
			int nans=0x3f3f3f3f;
			for(int i=0;i<(1<<n);i++){
				for(int j=1;j<=n;j++){
					if(i&(1<<(j-1))) v2[j]=1;
					else v2[j]=0;
				}
				nans=min(nans,check2());
			}
			cout<<nans<<"\n";
		}
	}
	
	return 0;
} 
