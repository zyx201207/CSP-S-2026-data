#include<bits/stdc++.h>
#define int long long
#define pii std::pair<int,int>
#define elif else if
const int maxn=505;
const int maxm=5e5+10;
const int inf=LLONG_MAX;
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		s=s*10+(c-'0');
		c=getchar();
	}
	return s*f;
}
int f[maxn][maxn];
std::vector<pii> g[maxm];
int w[maxm];
int n,m,c,d,q;
void init(){
	std::memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=m;++i){
		for(auto &u:g[i]){
			int uf=u.first,ul=u.second;
			for(auto &v:g[i]){
				int vf=v.first,vl=v.second;	 
				if(uf==vf)continue;
				f[uf][vf]=std::min(f[uf][vf],ul+vl);
			}	
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int k=1;k<=n;++k){
			for(int j=1;j<=n;++j){
				f[i][j]=std::min(f[i][j],f[i][k]+f[j][k]);
			}
		} 
	}
}
void solve(){
	for(int i=1;i<=q;++i){
		int u=read(),v=read();
		int ans=inf;
		for(auto &us:g[u]){
			int uf=us.first,ul=us.second;
			for(auto &vs:g[v]){
				int vf=vs.first,vl=vs.second;	 
				ans=std::min(ans,ul+vl+f[uf][vf]); 
			}	
		}
		printf("%lld\n",ans+w[u]+w[v]);
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;++i){
		w[i]=read();
	}
	for(int i=1;i<=n;++i){
		int ki=read();
		for(int j=1;j<=ki;++j){
			int ai=read(),ti=read();
			g[ai].push_back({i,ti});
		}
	}
	init();
	solve();
	return 0;
}
// 15:28
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/ 
 

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
/*
风把我不想知道的事情 告诉我
河把我不想忘记的故事 也带走
我摘下我的翅膀 它变成白鸟
白鸟我的白鸟 逆着风去吧

飞过河滩 挥一挥一去不回还
一去不回还 风起水起难靠岸
白鸟白鸟不要回头望
你要替我飞去那地方
一去那地方 那是你我共同故乡

抓住和抓不住的照片 哪张更美
去过和没去过的地方 哪里更远
白鸟我的白鸟 你要飞得更高不要回来
若还想与我相见 就来我的梦里边

白鸟过河滩
挥一挥一去不回还
一去不回还 风起水起难靠岸
白鸟白鸟不要回头望
你要替我飞去那地方
一去那地方 那是你我共同故乡

别回来
我将终究顺流入大海
顺流入大海 海不问我从何处来

长风长风飘在山海间
白鸟白鸟展翅入苍天
一去入苍天 苍天远在海背面 
一去入苍天 苍天远比海更远 
*/
