#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int buf[1<<10];
inline void print(int x,char ch=' '){
	if(x<0) putchar('-'),x=-x;
	int tot=0;
	do{
		buf[++tot]=x%10;
		x/=10;
	}while(x);
	for(int i=tot;i;i--)
		putchar(buf[i]+'0');
	putchar(ch);
}
const int N=1e6+5,inf=1e9;
int cid,tid;
int n,k;
pair<int,int> edge[N];
vector<int> e[N];
void add(int u,int v){
	e[u].push_back(v);
	e[v].push_back(u);
}

int dp[N][2];
void dfs1(int x,int dad){
	dp[x][0]=dp[x][1]=0;
	for(int to:e[x]){
		if(to==dad) continue;
		dfs1(to,x);
		if(dp[to][0]+1>dp[x][0]){
			dp[x][1]=dp[x][0];
			dp[x][0]=dp[to][0]+1;
		}
		else if(dp[to][0]+1>dp[x][1])
			dp[x][1]=dp[to][0]+1;
	}
}
int mxdp[N];
void dfs2(int x,int dad){
	mxdp[x]=dp[x][0];
	for(int to:e[x]){
		if(to==dad) continue;
		int cpy[4]={dp[x][0],dp[x][1],dp[to][0],dp[to][1]};
		if(dp[to][0]+1==dp[x][0])
			dp[x][0]=dp[x][1];
		if(dp[x][0]+1>dp[to][0]){
			dp[to][1]=dp[to][0];
			dp[to][0]=dp[x][0]+1;
		}
		else if(dp[x][0]+1>dp[to][1])
			dp[to][1]=dp[x][0]+1;
		dfs2(to,x);
		dp[x][0]=cpy[0];
		dp[x][1]=cpy[1];
		dp[to][0]=cpy[2];
		dp[to][1]=cpy[3];
	}
}

int f[N],g[N];
void solve1(int u,int *a){
	dfs1(u,0);
	for(int i=1;i<=n;i++) mxdp[i]=inf;
	dfs2(u,0);
	int rot=u;
	for(int i=1;i<=n;i++)
		if(mxdp[i]<=mxdp[rot]) rot=i;
	dfs1(rot,0);

	a[1]=dp[rot][0];
	priority_queue<pair<int,int>> q;
	for(auto to:e[rot])
		q.push(make_pair(dp[to][0],to));
	for(int i=2;i<=k;i++){
		if(q.empty()){
			a[i]=0;
			continue;
		}
		else{
			int x=q.top().second;
			q.pop();
			for(auto to:e[x])
				if(dp[to][0]<dp[x][0])
					q.push(make_pair(dp[to][0],to));
			if(q.empty()) a[i]=0;
			else a[i]=q.top().first+1;
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cid=read(),tid=read();
	while(tid--){
		n=read(),k=read();
		for(int i=1;i<n;i++){
			edge[i].first=read();
			edge[i].second=read();
		}
		if(n<=4000){
			int ans=inf;
			for(int i=1;i<n;i++){
				for(int j=1;j<=n;j++) e[j].clear();
				for(int j=1;j<n;j++){
					if(j==i) continue;
					add(edge[j].first,edge[j].second);
				}
				solve1(edge[i].first,f);
				solve1(edge[i].second,g);
				for(int j=1;j<k;j++)
					ans=min(ans,max(f[j],g[k-j]));
			}
			print(ans,'\n');
		}
		else{
			int N=197,fst=25,num=4,op=1;
			for(int i=N+1;i<=n;i++){
				if(op==1){
					if(num==4){
						fst++;
						num=1;
						op=0;
					}
					else{
						num++;
						op=0;
					}
				}
				else{
					op=1;
				}
			}
			for(int i=1;i<=num;i++)
				f[1+i]=fst;
			for(int i=2+num;i<=k;i+=4){
				if(f[i-1]==1) f[i]=f[i+1]=f[i+2]=f[i+3]=1;
				else f[i]=f[i+1]=f[i+2]=f[i+3]=f[i-1]-1;
			}
			cout<<f[k]<<endl;
		}
	}
	return 0;
}