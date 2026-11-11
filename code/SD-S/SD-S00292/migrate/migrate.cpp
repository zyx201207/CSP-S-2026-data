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
const int N=2e6+5;
int n,a[N],d,c,t,q[N],dp[N],l,r,in[N],tmp[N],dp2[N],cnt;
vector<int> v[N];
queue<int> q1;
void topu(int x){
	for(re int i=1;i<=n;++i) v[i].clear();
	memset(dp,0,sizeof(int)*(n+3));
	memset(in,0,sizeof(int)*(n+3));
	l=1,r=0;
	dp[x]=0;
	q[++r]=x;
	for(re int i=x+1;i<=n;++i){
		while(l<=r&&a[q[l]]<a[i]-d) l++;
		dp[i]=dp[q[l]]+1;
		while(l<=r&&dp[q[r]]>=dp[i]) r--;
		q[++r]=i;
	}
	for(re int i=x;i<=n;++i){
		for(re int j=i+1;j<=n&&a[j]-a[i]<=d;++j){
			if(dp[j]==dp[i]+1){
				v[i].push_back(j);
				in[j]++;
			}
		}
	}
	for(re int i=1;i<=n;++i) tmp[i]=in[i];
	memset(dp2,0,sizeof dp2);
	for(re int i=1;i<x;++i){
		for(re int j=0;j<v[i].size();++j){
			tmp[v[i][j]]--;
		}
	}
	for(re int i=x;i<=n;++i){
		if(!tmp[i]){
			q1.push(i);
		}
	}
	dp2[x]=1;
	while(q1.size()){
		int u=q1.front();
		for(re int i=0;i<v[u].size();++i){
			tmp[v[u][i]]--;
			dp2[v[u][i]]+=dp2[u];
			if(!tmp[v[u][i]]) q1.push(v[u][i]);
		}
		q1.pop();
	}
	for(re int i=x;i<=n;++i){
		if(dp2[i]==2){
			cnt++;
		}
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		cnt=0;
		for(re int i=1;i<=n;++i) a[i]=read();
		for(re int i=1;i<=n;++i) topu(i);
		write(cnt);
		putchar('\n');
	}
	return 0;
}
