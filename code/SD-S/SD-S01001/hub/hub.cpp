#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	char c;
	int re=0,f=1;
	while (1){
		c=getchar();
		if ('0'<=c and c<='9')	break;
		if (c=='-'){
			f=-1;c='0';
			break;
		}
	}
	while (1){
		re=re*10+c-'0';
		c=getchar();
		if (!('0'<=c and c<='9'))	return re*f;
	}
}
const int N=1e6+5;
struct edge{
	int nxt,to;
}e[N<<1];
int head[N],cnt;
int c,T,n,k;
bool flag[N];
int mid;
int cd[N],cd2[N];
void addedge(int x,int y){
	e[++cnt]={head[x],y};
	head[x]=cnt;
	cd[x]++;
}
int tp;
int vcnt;
int dp[N];
int f[N];
int flag2[N];
void bfs(){
	queue<pair<int,int> >q;
	for (int i=1;i<=n;i++)	cd2[i]=cd[i];
	for (int i=1;i<=n;i++)	if (cd[i]==1)	q.push({i,0});
	int cnt=0;
	while (q.size()){
		int x=q.front().first,v=q.front().second;
		cnt++;
		if (cnt==n)	tp=x;
//		cout<<x<<" "<<v<<"\n";
		q.pop();
		if (v==mid)	flag[x]=1,vcnt++;
		for (int i=head[x];i;i=e[i].nxt){
			cd2[e[i].to]--;
			if (cd2[e[i].to])	f[x]=e[i].to;
			if (cd2[e[i].to]==1)	q.push({e[i].to,v+1});
		}
	}
	for (int i=head[tp];i;i=e[i].nxt)	f[e[i].to]=tp;
}
int cntt;
int dp2[N];
void mem(int x,int v){
	if (!flag2[x])	cntt++;
	flag2[x]=v;
	if (v==1)	return ;
	for (int i=head[x];i;i=e[i].nxt)
		if (flag2[e[i].to]<v-1)
			mem(e[i].to,v-1); 
}
void dfs2(int x){
	flag[x]=1,vcnt++;
	for (int i=head[x];i;i=e[i].nxt)
		if (dp[e[i].to] and !flag[e[i].to])
			dfs2(e[i].to);
}
void dfs(int x){
	dp[x]=0;
	if (flag[x])
		mem(x,mid+1); 
	for (int i=head[x];i;i=e[i].nxt)
		if (e[i].to!=f[x]){
			dfs(e[i].to);
			dp[x]+=dp[e[i].to];
			dp2[x]+=dp2[e[i].to];
		}
	if (flag[x])	dp[x]=1;
	if (dp[x]>2 or (dp[x]==2 and dp2[x]==vcnt)){
		dfs2(x);
		dfs(x);
	}
}
bool flag3[N];
int zx;
void ck(int x,int v){
	if (!flag2[x])	zx=1;
	if (zx)	return ;
	for (int i=head[x];i;i=e[i].nxt)
		if (flag2[e[i].to]<v-1)
			ck(e[i].to,v-1); 
}
void bfs2(){
	queue<int >q;
	for (int i=1;i<=n;i++)	if (flag[i]==1)	flag3[i]=1,q.push(i);
	int cnt=0;
	while (cntt<n and q.size()){
		int x=q.front();
//		cout<<x<<" "<<q.size()<<" "<<cntt<<"\n";
		q.pop();
		zx=0;
		if (!flag[x]){
			ck(x,mid+1);
			if (zx)	flag[x]=1,vcnt++,mem(x,mid+1);//cout<<x<<"s";
		}	
		for (int i=head[x];i;i=e[i].nxt){
			if (!flag3[e[i].to])	flag3[e[i].to]=1,q.push(e[i].to);
		}
	}
}
bool check(){
	memset(dp2,0,sizeof(dp2));
	memset(flag,0,sizeof(flag));
	memset(f,0,sizeof(f));
	memset(dp,0,sizeof(dp));
	memset(flag2,0,sizeof(flag2));
	memset(flag3,0,sizeof(flag3));
	vcnt=cntt=0;
	bfs();
//	cout<<mid<<" "<<tp<<" "<<cntt<<" "<<vcnt<<"a\n";
//	for (int i=1;i<=n;i++)	cout<<flag[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)	cout<<f[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)	cout<<dp[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)	cout<<flag2[i]<<" ";
//	cout<<"\n";
	dfs(tp);
//	cout<<mid<<" "<<tp<<" "<<cntt<<" "<<vcnt<<"b\n";
//	for (int i=1;i<=n;i++)	cout<<flag[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)	cout<<f[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)	cout<<dp[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)	cout<<flag2[i]<<" ";
//	cout<<"\n";
	if (vcnt==0)	return 1;
	if (vcnt>k)	return 0;
	if (cntt==n)	return 1;
	bfs2();
//	cout<<mid<<" "<<tp<<" "<<cntt<<" "<<vcnt<<"c:\n";
//	for (int i=1;i<=n;i++)	cout<<flag[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)	cout<<f[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)	cout<<dp[i]<<" ";
//	cout<<"\n";
//	for (int i=1;i<=n;i++)	cout<<flag2[i]<<" ";
//	cout<<"\n";
	if (vcnt>k)	return 0;
	if (cntt==n)	return 1;
	return 1;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while (T--){
		memset(cd,0,sizeof(cd));
		memset(head,0,sizeof(head));cnt=0;
		n=read(),k=read();
		for (int i=1;i<n;i++){
			int x=read(),y=read();
			addedge(x,y);
			addedge(y,x);
		}
		int l=1,r=n,ans;
		while (l<=r){
			mid=(l+r)>>1;
			if (check())	ans=mid,r=mid-1;
			else	l=mid+1;
		}
		cout<<ans<<"\n";
	}
}

