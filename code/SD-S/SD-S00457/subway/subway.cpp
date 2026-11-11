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
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	return x*f;
}
const int N=505,maxn=5e5+5;
int c,n,m,d,q,w[maxn];
long long dis[N][N];
struct Node{
	int u,val;
};
vector<Node>t[N];
vector<Node>f[maxn];
bool cmp(Node x,Node y){
	return x.u<y.u;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	c=r,n=r,m=r,d=r,q=r;
	for(int i=1;i<=m;i++)w[i]=r;
	for(int i=1;i<=n;i++){
		int k=r;
		for(int j=1;j<=k;j++){
			int x=r,y=r;
			t[i].push_back({x,y});
			f[x].push_back({i,y});//f[x].size<=20
		}
		sort(t[i].begin(),t[i].end(),cmp);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ls=0,lr=0;
			while(ls<(int)t[i].size()){
				while(t[i][ls].u>t[j][lr].u){
					if(lr==(int)t[j].size()-1)break;
					++lr;
				}
				if(lr==(int)t[j].size()-1)break;
				if(t[i][ls].u!=t[j][lr].u){
					++ls;
					continue;
				}
				dis[i][j]=min(dis[i][j],0ll+t[i][ls].val+t[j][lr].val);
				dis[j][i]=dis[i][j];
				++ls;
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
		}
	}
	while(q--){
		int x=r,y=r;
		long long ans=LLONG_MAX;
		int siz1=f[x].size(),siz2=f[y].size();
		for(int i=0;i<siz1;i++){
			for(int j=0;j<siz2;j++){
				ans=min(ans,0ll+f[x][i].val+dis[f[x][i].u][f[y][j].u]+f[y][j].val);
			}
		}
		printf("%lld\n",0ll+w[x]+w[y]+ans);
	}
	return 0;
}
