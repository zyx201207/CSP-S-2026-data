#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,NN=1e5+5;
int c,t,n,d,k,a[N],b[N],vis[NN],dis[N][N],anss,m;
vector<int>G[NN];
void Dfs(int x){
	b[x]=2;
	for(auto v:G[x])
	   if(b[v]==1)Dfs(v);
}
void dfs(int x,int T){
	if(T>d)return ;
	if(x>n){
		if(T!=d)return ;
		int block=0;
		for(int i=1;i<=n;i++)b[i]=vis[i];
		for(int i=1;i<=n;i++)
		   if(b[i]==1)block++,Dfs(i);
		if(block>2)return ;
		int ans=0;
		for(int i=1;i<=n;i++){
			int mi=2e9;
			for(int j=1;j<=n;j++)
			   if(vis[j])mi=min(mi,dis[i][j]);
			ans=max(ans,mi);
		}
		anss=min(anss,ans);
		return ;
	}
	vis[x]=1,dfs(x+1,T+1);
	vis[x]=0,dfs(x+1,T);
}
void dfs1(int x,int s,int y,int fa){
	dis[y][x]=s;
	for(auto v:G[x])
	   if(v!=fa)dfs1(v,s+1,y,x);
}
bool check(int x){
	if(x==0)return n<=d;
	int tot=0;
	vector<int>v;
	for(int i=x;i<=m+1;i+=2*x-1)tot++,v.push_back(i);
	if(m+1-v[tot-1]>x)v.push_back(m+1-x),tot++;
	if(tot<=2)return 1;
	for(int i=tot-1;i>=2;i--)tot+=v[i]-v[i-1];
	return tot<=d;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
    	cin>>n>>d;
    	for(int i=1;i<=n;i++)vis[i]=0,G[i].clear();
    	for(int i=1;i<n;i++){
    		int u,v;cin>>u>>v;
    		G[u].push_back(v);
    		G[v].push_back(u);
		}
		if((c==13||c==14)&&n>10){
			m=n/2;
			int l=0,r=m+1,ans=0;
			while(l<=r){
				int mid=(l+r)>>1;
				if(check(mid))ans=mid,r=mid-1;
				else l=mid+1;
			}
			cout<<ans<<"\n";
		}else {
			anss=2e9;
		    for(int i=1;i<=n;i++)
    	       dfs1(i,0,i,0);
			dfs(1,0);
			cout<<anss<<"\n";
		}
	}
	return 0;
}/*
分析一下T4,15pts的暴力是好拿的,那么+15pts

let me guess the nan du

T1:orange it is so water
T2:green bacause it is more eassier than last year
T3:qing I can not spell qing in English ,because T3 is not difficult
T4 purper I can not get more pts
100+100+48+15=263pts
I think I can get sqrt(7)

but If I can not get the rank 200- in ZJ,I will AFO.
Because if I want to go to the better middle senior school in Cixi,Ning bo by oi,I should get the rank 200-.
Last year,I got 100+80+20+8=208pts,rank 200+
I think I can do it!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

17:23 : I write the passage.
now I should do T4 again and get more pts.

17:28 : I think I can solve the A
这似乎是个二分+贪心，在1~m这条主链上放点就行了

17:41 :find A is boom

17:51 : I solve the Ahub5!!!!!!!!!!!!!!!!!!!
so I get can 100+100+48+25=273pts
let me think migrate.

18:10 : I give up.I shoule be careful,I can not gua fen.

18:22 : I want to go to the WC,but the teacher do not let me go,because the time is in -15min~0min
CCF I love you!

@123lusicheng
@cxoi1501
@cxoi1588
@IronLotus_
@William_Alice
@zhuchenyi712
@_happy_hen_
@wengruqin
@zyc123
@slzxchenyuxuan
@slzxsunjiawen
@slzxhqx
@ztm
@lyc
你们都给我拿S1
@_zjf_ 膜拜初二2*sqrt(2)
@yujian2025
@sadtime 感谢以上这两位的florr账号,lvl122,s rice->s coin s mecha chu jiao,and we have U nazar and U totem
@trz
@wsc
膜拜机房大佬%%%%%%%%%%%%%%%%\bx \bx \bx
sorry,ztm,lyc,trz,wsc,I forget your name of luogu.

----------------------------------|
|    永     远     缅     怀      |
----------------------------------|
|    |                       |    |
| 张 |                       | 我 |
|    |                       |    |
| 锦 |                       | 还 |
|    |                       |    |
| 锋 |                       | 记 |
|    |                       |    |
| 老 |                       | 得 |
|    |                       |    |
| 师 |                       | 你 |
|    |                       |    |
|---------------------------------|
|              _zjf_              |
|---------------------------------|

永远缅怀，初二APIO银牌 -> @_zjf_

luogu:zg_AKer
*/