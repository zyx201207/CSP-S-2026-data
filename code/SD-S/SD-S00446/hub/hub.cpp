#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int n,t,c,m,fl[100001],fa[100001],w[1001][1001],dp[1001][1001],ans;
vector<int>v[100001];
set<int>st;
long long read() {
	long long ret=0,sgn=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9') {
		sgn=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		ret*=10;
		ret+=c-48;
		c=getchar();
	}
	return ret*sgn;
}
int gtf(int x){
	if(fa[x]==x)return x;
	return fa[x]=gtf(fa[x]);
}
bool ck(int x){
	st.clear();
	int cnt=0,tmp=x;
	while(tmp){
		cnt+=(tmp&1);
		tmp>>=1;
	}
	if(cnt!=m)return 0;
	for(int i=1;i<=n;i++){
		fl[i]=(bool)(x&(1<<(i-1)));
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(!fl[i])continue;
		for(int j=0;j<(int)v[i].size();j++){
			if(!fl[v[i][j]])continue;
			int a=gtf(i),b=gtf(v[i][j]);
			if(a==b)continue;
			fa[b]=a;
		}
	}
	for(int i=1;i<=n;i++){
		if(fl[i]){
			st.insert(gtf(i));
		}
	}
	return st.size()<=2;
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();
	t=read();
	while(t--) {
		ans=10000000;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		n=read();
		m=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=100000000;
				w[i][j]=100000000;
			}
			dp[i][i]=0;
		}
		for(int i=1;i<n;i++){
			int x,y;
			x=read();
			y=read();
			v[x].push_back(y);
			v[y].push_back(x);
			dp[x][y]=1;
			dp[y][x]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		for(int i=0;i<(1<<n);i++){
			if(ck(i)){
				int tmp=0;
				for(int j=1;j<=n;j++){
					if(!fl[j]){
						int t2=100000000;
						for(int k=1;k<=n;k++){
							if(fl[k]){
								t2=min(t2,dp[j][k]);
							}
						}
						tmp=max(tmp,t2);
					}
				}
				ans=min(ans,tmp);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
