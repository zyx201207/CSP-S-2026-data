#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#define re register
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar('0'+x%10);
}
const int N=1005;
int c,t,n,k,x,y,vis[N],vis2[N],ans=2e6;
vector<int> v[N];
void sch(int x){
	vis2[x]=1;
	for(re int i=0;i<=v[x].size();++i){
		if(vis[v[x][i]]&&(!vis2[v[x][i]])) sch(v[x][i]);
	}
}
bool check(){
	int res=0;
	memset(vis2,0,sizeof vis2);
	for(re int i=1;i<=n;++i){
		if(vis[i]&&(!vis2[i])){
			res++;
			sch(i);
		}
	}
	if(res!=2) return 0;
	else return 1;
}
int sch2(int x){
	int d=2e7;
	for(re int i=0;i<v[x].size();++i){
		if(vis[v[x][i]]) return 0;
		else d=min(d,1+sch2(v[x][i]));
	}
	return d;
}
int get(){
	int res=0;
	for(re int i=1;i<=n;++i){
		if(vis[i]) continue;
		res=max(res,sch2(i));
	}
}
void dfs(int x,int cnt,int cho){
	if(x==n+1){
		if(cnt==k){
			memset(vis,0,sizeof vis);
			int now=1;
			while(cho){
				if(cho&1) vis[now]=1;
				cho>>=1;
				now++;
			}
			if(check()){
				ans=min(ans,get());
			}
		}
		return;
	}
	dfs(x+1,cnt,cho);
	if(cnt<k) dfs(x+1,cnt+1,cho|(1<<(x-1)));
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),k=read();
		for(re int i=1;i<=n;++i) v[i].clear();
		for(re int i=1;i<n;++i){
			x=read(),y=read();
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(n==k){
			write(0);
			putchar('\n');
		}else if(k==n-1){
			write(1);
			putchar('\n');
		}else if(k==n-2){
			write(1);
			putchar('\n');
		}else{
			dfs(1,0,0);
			write(ans);
			putchar('\n');
		}
	}
	return 0;
}
