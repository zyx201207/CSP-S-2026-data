#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500002];
int cnt[500002],ln[500002][22],mp[500002][22];
int k[502];
vector<pair<int,long long> >a[502];
long long e[502][502];
long long f[502][502];
bool vis[502][502];
void dijkstra(int s){
	for(int i=1;i<=n-s;i++){
		int u;
		long long mn=0x3f3f3f3f3f3f3f3f;
		for(int j=s+1;j<=n;j++){
			if(!vis[s][j]){
				if(f[s][j]<mn){
					mn=f[s][j];
					u=j;
				}
			}
		}
//		cerr<<u<<' ';
		vis[s][u]=1;
		for(int j=s+1;j<=n;j++){
			f[s][j]=min(f[s][j],f[s][u]+e[u][j]);
		}
	}
//	cerr<<'\n';
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cerr<<f[i][j]<<' ';
//		}
//		cerr<<'\n';
//	}
}
void init(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[i][j]=e[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			f[j][i]=f[i][j];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cerr<<f[i][j]<<' ';
//		}
//		cerr<<'\n';
//	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	memset(e,0x3f,sizeof e);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		e[i][i]=0;
		for(int j=0;j<k[i];j++){
			int u,t;
			scanf("%d%d",&u,&t);
			a[i].push_back(make_pair(u,t));
			ln[u][++cnt[u]]=i;
			mp[u][cnt[u]]=j;
		}
	}
	for(int i=1;i<=m;i++){
		for(int u=1;u<=cnt[i];u++){
			for(int v=u+1;v<=cnt[i];v++){
				e[ln[i][u]][ln[i][v]]=min(e[ln[i][u]][ln[i][v]],a[ln[i][u]][mp[i][u]].second+a[ln[i][v]][mp[i][v]].second);
				e[ln[i][v]][ln[i][u]]=e[ln[i][u]][ln[i][v]];
			}
		}
	}
	init();
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=cnt[u];i++){
			for(int j=1;j<=cnt[v];j++){
				ans=min(ans,a[ln[u][i]][mp[u][i]].second+f[ln[u][i]][ln[v][j]]+a[ln[v][j]][mp[v][j]].second);
			}
		}
//		cerr<<w[u]+ans+w[v]<<'\n';
		printf("%lld\n",w[u]+ans+w[v]);
	}
	return 0;
}
/*
qilai jihanjiaopodenuli
qilai quanshijieshoukuderen
manqiangderexueyijingfeiteng
yaoweizhenlierdouzheng
jiushijie dageluohualiushui
bulimenqilaiqilai
buyaoshuowomenyiwusuoyou
womenyaozuotianxiadezhuren
zheshizuihoudidouzheng
tuanjieqilaidaomingtian
yingtenaxiongnaer
jiuyidingyaoshixian
zheshizuihoudidouzheng
tuanjieqilaidaomingtian
yingtenaxiongnaer
jiuyidingyaoshixian

conglaijiumeiyoushenmejiushizhu
yebukaoshenxianhuangdi
yaochuangzaorenleidexingfu
quankaowomenziji
womenyaoduohuilaodongguoshi
rangsixiangchongpolaolong
quanbanaluhuoshaodetonghong
chenredatiecainengchenggong
zheshizuihoudidouzheng
tuanjieqilaidaomingtian
yingtenaxiongnaer
jiuyidingyaoshixian
zheshizuihoudidouzheng
tuanjieqilaidaomingtian
yingtenaxiongnaer
jiuyidingyaoshixian

shishuichuangzaolerenleishijie
shiwomenlaodongqunzhong
yiqieguilaodongzhesuoyou
nalirongdeliaojishengchong
zuikehennaxiedushemengshou
chijinliaowomendexuerou
yidanbatamenxiaomieganjing
xianhongdetaiyangzhaobianquanqiu
zheshizuihoudidouzheng
tuanjieqilaidaomingtian
yingtenaxiongnaer
jiuyidingyaoshixian
zheshizuihoudidouzheng
tuanjieqilaidaomingtian
yingtenaxiongnaer
jiuyidingyaoshixian

kenengdacuozile,meishijianjianchale,buyongguanta,benlai<guojige>jiubujuniyuyuyan.
kaole 4 cimeiyoujinguomihuoxingweidashang,rangwoshangyiciba,xiexie.

int mian()
fropen
return 1;

xiewanzhexiehaiyou 4min,quxiedianbiededongxizengjiawoshangdashangdjihui.
fanzhengwoshigaozhongsheng,wobuzaihu CSP-S dechengji,jinbuliao WC yemeiguanxi.

zhetibuyaokachang,baituole CCF.
buxiangxiekuaidu.
*/