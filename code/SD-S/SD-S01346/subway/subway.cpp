//By JuRuoOIer
//Problem:subway
//Expected:100 (kd+n^3+qd^2)
//idea:21min impl:9min
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<cctype>
#include<random>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define LL __int128
#define lf double
#define ld long double
using namespace std;
void file(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
ll n,m,q,u,v,c,dis[510][510],w[500010];
vector<ll> a[500010],t[500010]; 
int main(){
	file();
	ios::sync_with_stdio(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		cin>>c;
		while(c--){
			cin>>u>>v;
			for(int j=0;j<a[u].size();j++){
				dis[i][a[u][j]]=min(dis[i][a[u][j]],v+t[u][j]);
				dis[a[u][j]][i]=min(dis[a[u][j]][i],v+t[u][j]);
			}
			a[u].push_back(i);
			t[u].push_back(v);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--){
		cin>>u>>v;
		ll ans=999999999999999999ll;
		for(int i=0;i<a[u].size();i++){
			for(int j=0;j<a[v].size();j++){
				ans=min(ans,w[u]+w[v]+t[u][i]+t[v][j]+dis[a[u][i]][a[v][j]]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
ËêÊÜÐ» Ñà´Ç¹é
È¥°×ÈÕ æðÌ«Î¢
Óõàµ Ç¼Ë¹Â·Ö®ŸzŸzÙâ²»¿É×·
šG ¶­µÀÙâ³£Î¥
å¿ ?ÙâÆäÍù ËïÙâƒ{Ý
Í½ÀëÓÇÙâÆäÍù Êë½«Îª
?ÙâÆäÍù ?ÙâÆäÍù ÎÞ±¯

ºÎ·½¹é ÑàË«ËÞ
ºÎ·½·ê ÒøâGÖò
ÃÎ¾õÓñîÎ·Ö´¦ ÐþÄñÈ¥ÔÆÓÆÓÆ
Áô ÓêÁåÆ¾Ë­Ëß
ºÞ ·¼ÄêÙ¿ºö ÖìÑÕÄÑ×¤
È´Äî ÇàÉ½ÓÀ¹Ì ×ÜÄýÄ¿
µ«ÎªºÎ¹Ê ÖªÎÒÏà¸º Î´¸º 
*/
