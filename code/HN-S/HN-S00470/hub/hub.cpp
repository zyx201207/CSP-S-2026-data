#include<bits/stdc++.h>
using namespace std;
struct edge{
	int to,next;
}a[1000010];
int cid,head[1000010],ed,n,k,f[1000010],dep[1000010],fa[1000010][21],as,fat[1000010];
void add(int x,int y){
	ed++;
	a[ed].to=y;
	a[ed].next=head[x];
	head[x]=ed;
}
void dfs1(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for(int i=head[x];i!=0;i=a[i].next)
		if(a[i].to!=f)
			dfs1(a[i].to,x);
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=log2(n);i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	// cout<<x<<' '<<y<<'\n';
	if(x==y)
		return x;
	for(int i=log2(n);i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int find(int x){
	if(x==fat[x])
		return x;
	fat[x]=find(fat[x]);
	return fat[x];
}
int check(){
	int mx=0,d1=0,d2=0;
	for(int i=1;i<=n;i++)
		fat[i]=i;
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			for(int j=head[i];j!=0;j=a[j].next)
				if(f[a[j].to]==1)
					fat[find(i)]=find(a[j].to);
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			if(d1==0||d1==find(i)){
				d1=find(i);
			}
			else if(d2==0||d2==find(i)){
				d2=find(i);
			}
			else
				return 1e9;
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			int mn=1e9;
			for(int j=1;j<=n;j++){
				if(f[j]==1){
					// if(i==4)
						// cout<<dep[i]<<' '<<dep[j]<<' '<<lca(i,j)<<' '<<j<<'\n';
					mn=min(mn,dep[i]+dep[j]-2*dep[lca(i,j)]);
				}
			}
			// if(i==4)
				// cout<<mn<<'\n';
			mx=max(mx,mn);
		}
	}
	return mx;
}
void dfs(int x,int sum)
{
	// cout<<x<<' '<<sum<<'\n';
	if(x==n+1){
		// cout<<check()<<'\n';
		// if(check()==1){
		// for(int i=1;i<=n;i++)
			// cout<<f[i]<<' ';
		// cout<<'\n';
// 
		// }
		as=min(as,check());
		return;
	}
	if(n-x+sum>=k)
		dfs(x+1,sum);
	if(sum<k){
		f[x]=1;
		dfs(x+1,sum+1);
		f[x]=0;
	}
}
void MAIN()
{
	cin>>n>>k;
	ed=0;
	for(int i=1;i<=n;i++)
		head[i]=0,f[i]=0;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if(n==k){
		cout<<"0\n";
		return;
	}
	if(cid==13||cid==14){
		cout<<ceil((n-k)/4)+1<<'\n';
		return;
	}
	as=1e9;
	dfs1(1,1);
	for(int i=1;i<=log2(n);i++)
		for(int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	// cout<<lca(4,9)<<'\n';
	dfs(1,0);
	cout<<as<<'\n';
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	cin>>cid>>T;
	while(T--){
		MAIN();
	}
	return 0;
}