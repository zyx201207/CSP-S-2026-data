#include<bits/stdc++.h>
//#define ector vector
using namespace std;
inline int read(){
	int x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=1e6+100;
int n;
int k;
vector<int>g[N];
int Ma[N];
int ma(int a,int b){
	return a>b?a:b;
}
bool usd[N];
void get_root(int u,int fa){
	usd[u]=1;
	for(auto S :g[u]){
		if(S==fa)continue;
		get_root(S,u);
		Ma[u]=ma(Ma[S]+1,Ma[u]);
	}
	return;
}
void calc(int u,int fa,int G){
	Ma[u]=ma(Ma[u],G);
	vector<int>pre;
	for(auto S : g[u]){
		if(S==fa)continue;
		pre.push_back(Ma[S]+1);
	}
	vector<int>sub;
	sub=pre;
	reverse(sub.begin(),sub.end());
	for(int i=1;i<(int)pre.size();i++)pre[i]=ma(pre[i],pre[i-1]);
	for(int i=(int)sub.size()-2;i>=0;i--)sub[i]=ma(sub[i+1],sub[i]);
	int cnt=0;
	for(auto S : g[u]){
		if(S==fa)continue;
		int Pre=0;
		int Sub=0;
		if(cnt)Pre=pre[cnt-1]; 
		if(cnt+1<(int)sub.size())Sub=ma(Sub,sub[cnt+1]);
		calc(S,u,ma(Pre,Sub));
		cnt++;
	}
	return;
}
int dis[N];
void Cl(int u,int fa,int dep){
	dis[u]=min(dis[u],dep);
	for(auto S : g[u]){
		if(S==fa)continue;
		Cl(S,u,dep+1);
	}
	return;
}
void clear(){
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++){
		dis[i]=0;
		Ma[i]=0;
		usd[i]=0;
	}
	return;
}
void solve(){
	n=read();
	k=read();
	for(int i=1;i<n;i++){
		int u=read();
		int v=read();
		g[u].push_back(v);
		g[v].push_back(u);	
	}
	if(n==k){
		cout<<0<<"\n";
		clear();
		return;
	}
	if(n==k-1){
		cout<<1<<"\n";
		clear();
		return;
	}
	get_root(1,0);
	calc(1,0,0);
	int Id1=-1;
	int Man=1e9;
	for(int i=1;i<=n;i++){
		if(Ma[i]<Man)Man=Ma[i],Id1=i;
	}
	int Rt1=Id1;
	for(int i=1;i<=n;i++)Ma[i]=0,usd[i]=0;
	int Id2=0;
	Man=1e9;
	for(auto S : g[Rt1]){
		get_root(S,Rt1);
		if(Ma[S]<Man)Man=Ma[S],Id2=S;
	}
	for(int i=1;i<=n;i++)Ma[i]=0,usd[i]=0;
	get_root(Id2,Id1);
	calc(Id2,Id1,0);
	Man=1e9;
	for(int i=1;i<=n;i++){
		if(!usd[i])continue;
		if(Ma[i]<Man)Man=Ma[i],Id2=i;
	}
	for(int i=1;i<=n;i++)dis[i]=1e9;
	Cl(Id1,0,0);
	Cl(Id2,0,0);
	int ans=-1e9;
	for(int i=1;i<=n;i++)ans=ma(ans,dis[i]);
	cout<<ans<<"\n";
	clear();
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read();
	int T=read();
	while(T--)solve();
	return 0;
}
