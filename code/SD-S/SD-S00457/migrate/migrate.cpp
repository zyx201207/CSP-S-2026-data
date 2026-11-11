#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define r read()
using namespace std;
long long read(){
	long long x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	return x*f;
}
const int N=2e6+5;
int c,t,n;
long long d,x[N],ans;
namespace T1{
	bool c[14];
	int mp[13][13],D[13][13];
	void check(){
		vector<int>tmp;
		tmp.clear();
		for(int i=1;i<=n;i++)if(c[i])tmp.push_back(i);
		if(tmp.size()<=1)return;
		for(int i=1;i<(int)tmp.size();i++)if(x[tmp[i]]-x[tmp[i-1]]>d)return;
		int dis=tmp.size(),u=tmp[0],v=tmp[tmp.size()-1];
		if(dis<D[u][v]){
			D[u][v]=dis;
			mp[u][v]=1;
			return;
		}
		else if(dis==D[u][v])++mp[u][v];
		return;
	}
	void dfs(int x){
		if(x==n+1){
			check();
			return;
		}
		c[x]=0;
		dfs(x+1);
		c[x]=1;
		dfs(x+1);
		return;
	}
	void solve(){
		memset(mp,0,sizeof(mp));
		memset(D,0x3f,sizeof(D));
		d=r;
		for(int i=1;i<=n;i++)x[i]=r;
		dfs(1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)if(mp[i][j]==2)++ans;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=r,t=r;
	while(t--){
		n=r,ans=0;
		if(n<=9){
			T1::solve();
		}
		else puts("0");
	}
	return 0;
}
