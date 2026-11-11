#include<bits/stdc++.h>
using namespace std;
long long read(){
	char c=getchar();
	long long res=0;
	short f=1;
	while(c<'0' || c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return f*res;
}
void write(long long x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int aaaaa,t;
int n,m;
vector<int> v[2000005];
int fa[2000005],dep[2000005];
void dfs(int x,int ff){
	dep[x]=dep[ff]+1;
	fa[x]=ff;
	for(int i=0;i<v[x].size();i++){
		if(v[x][i]!=ff){
			dfs(v[x][i],x);
		}
	}
}
int a[2000005];
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]>dep[y])x=fa[x];
	while(x!=y)x=fa[x],y=fa[y];
	return x;
}
int ans=0x3f3f3f3f;
void dfs2(int x,int num){
	if(num==m){
		int mx=0;
		for(int i=1;i<=n;i++){
			int mn=0x3f3f3f3f;
			for(int j=1;j<=m;j++){
				mn=min(mn,dep[i]-dep[lca(i,a[j])]+dep[a[j]]-dep[lca(i,a[j])]);
				//cout<<i<<" "<<fa[i]<<" "<<" "<<lca(i,a[j])<<" "<<dep[i]-dep[lca(i,a[j])]+dep[a[j]]-dep[lca(i,a[j])]+1<<endl;
			}
			mx=max(mn,mx);
		}
		//for(int i=1;i<=m;i++)cout<<a[i]<<" ";cout<<mx<<endl;
		ans=min(ans,mx);
		return;
	}
	for(int i=x+1;i<=n;i++){
		a[num+1]=i;
		dfs2(i,num+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	aaaaa=read();
	t=read();
	while(t--){
		n=read(),m=read();
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			v[x].push_back(y),v[y].push_back(x);
		}
		dfs(1,0);
		//for(int i=1;i<=n;i++)cout<<i<<" "<<dep[i]<<endl;
		ans=0x3f3f3f3f;
		dfs2(0,0);
		write(ans);
		putchar('\n');
	}
	return 0;
}
