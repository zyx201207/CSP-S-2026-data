#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,r,dep[N],n,k,ans,kk,fa[N];
vector<int>v[N];
bool is[20];
struct node{
	int x,y;
}xx[N];
int find(int x){
	if(fa[x]==0)return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(int p,int f){
	dep[p]=dep[f]+1;
	if(dep[p]>dep[r]){
		r=p;
		if(dep[p]==1){
			//cout<<p<<" "<<r<<"\n";
		}
		//cout<<dep[r]<<"\n";
	}
	for(auto son:v[p]){
		if(f==son)continue;
		dfs(son,p);
	}
	return;
}
void dfs3(int p,int f){
	dep[p]=dep[f]+1;
	if(kk!=-1)return;
	if(is[p]){
		kk=dep[p]-1;
		return;
	}
	for(auto son:v[p]){
		if(f==son)continue;
		dfs3(son,p);
	}
	return;
}
void dfs2(int x,int num){
	if(num+n-x<k)return;
	if(num==k){
		int res=0;
		int sum=k;
		for(int i=1;i<=n;i++)fa[i]=0;
		for(int i=1;i<n;i++){
			if(is[xx[i].x]&&is[xx[i].y]){
				if(find(xx[i].x)!=find(xx[i].y)){
					sum--;
					fa[find(xx[i].x)]=find(xx[i].y);
				}
			}
		}
		if(sum>2)return;
		for(int i=1;i<=n;i++){
			//cout<<is[i]<<" ";
			for(int j=1;j<=n;j++)dep[j]=0;
			kk=-1;
			dfs3(i,0);
			res=max(res,kk);
		}
		//cout<<"\n";
		//cout<<res<<"\n";
		//if(res==1)cout<<"xxxxxxx\n";
		ans=min(ans,res);
		return;
	}
	is[x+1]=0;
	dfs2(x+1,num);
	is[x+1]=1;
	dfs2(x+1,num+1);
	is[x+1]=0;
	return;
}
void solve(){
	int a,b;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
		xx[i]={a,b};
	}
	if(c<=3){
		ans=n;
		dfs2(0,0);
		cout<<ans<<"\n";
	}else if(k==2){
		for(int i=1;i<=n;i++)dep[i]=0;
		r=0;
		dfs(1,0);
		for(int i=1;i<=n;i++)dep[i]=0;
		//cout<<r<<" "<<n<<"\n";
		dfs(r,0);
		//cout<<r<<" "<<dep[r]<<"\n";
		cout<<dep[r]/4<<"\n";
	}else{
		if(n==k){
			cout<<0<<"\n";
		}else if(k>=n/2){
			cout<<1<<"\n";
		}else{
			cout<<(n/2-k-1)/4+2<<"\n";
		}
	}
	for(int i=1;i<=n;i++)v[i].clear();
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
