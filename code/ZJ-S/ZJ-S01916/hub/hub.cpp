#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
const int M=25;
struct node{
	int x,dfn;
	friend bool operator < (node t1,node t2){
		return t1.dfn<t2.dfn;
	}
}t[N];
int n,k,cnt,num,len,tot;
int sum1[N],sum2[N];
int dfn[N],dep[N],ans[N][M];
int f[N],h[N],to[N],nxt[N];
void add(int a,int b){
	cnt++;
	to[cnt]=b;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
void init(){
	for(int j=1;j<=21;j++)
	for(int i=1;i<=n;i++)
		ans[i][j]=ans[ans[i][j-1]][j-1];
}
int lca(int u,int v){
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=21;i>=0;i--)
		if(dep[ans[u][i]]>=dep[v])
			u=ans[u][i];
	if(u==v) return u;
	for(int i=21;i>=0;i--)
		if(ans[u][i]!=ans[v][i])
			u=ans[u][i],v=ans[v][i];
	return ans[u][0];
}
int res(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)]+1;
}
void dfs1(int x,int fa){
	dfn[x]=++tot;
	dep[x]=dep[fa]+1;
	ans[x][0]=fa;
	for(int i=h[x];i;i=nxt[i]){
		int u=to[i];
		if(u==fa) continue;
		dfs1(u,x);
	}
}
void dfs2(int x,int fa){
	for(int i=h[x];i;i=nxt[i]){
		int u=to[i];
		if(u==fa) continue;
		dfs2(u,x),f[x]=max(f[x],f[u]+1);
	}
	if(f[x]>=len){
		num++,f[x]=-1;
		t[num]={x,dfn[x]};
	}
}
bool check(int x){
	len=x,num=0;
	for(int i=1;i<=n;i++)
		f[i]=0;
	dfs2(1,0);
	sort(t+1,t+num+1);
	if(num<=1) return true;
	for(int i=0;i<=num+1;i++)
		sum1[i]=sum2[i]=0;
	for(int i=1;i<=num;i++){
		if(i==1) continue;
		sum1[i]=sum1[i-1]+res(t[i].x,t[i-1].x);
	}
	for(int i=num;i>=1;i--){
		if(i==n) continue;
		sum2[i]=sum2[i+1]+res(t[i].x,t[i+1].x);
	}
	for(int i=1;i<=num;i++){
		if(i!=1) sum1[i]+=res(t[i].x,t[1].x);
		if(i!=num) sum2[i]+=res(t[i].x,t[num].x);
	}
	int minn=1e15;
	for(int i=1;i<num;i++){
		int ans=(sum1[i]+sum2[i+1])/2;
		minn=min(minn,ans);
	}
	return minn<=k;
}
void solv(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	init();
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	cout<<ans<<"\n";
	n=k=cnt=num=len=tot=0;
	memset(h,0,sizeof h);
	memset(to,0,sizeof to);
	memset(nxt,0,sizeof nxt);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
		solv();
	return 0;
}
/*

*/