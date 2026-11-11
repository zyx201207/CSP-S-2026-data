//By JuRuoOIer
//Problem:hub
//Expected:15 (n*2^n)
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
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
}
ll c,T,n,k,u,v,msk,vis[1000010],dis[1000010];
vector<ll> a[1000010];
void dfs(ll now,ll lst,ll d){
	dis[now]=min(dis[now],d);
	vis[now]=1;
	for(int i=0;i<a[now].size();i++){
		if(a[now][i]!=lst&&((msk>>now-1)&1)>=((msk>>a[now][i]-1)&1)){
			dfs(a[now][i],now,d+1-((msk>>a[now][i]-1)&1));
		}
	}
}
int main(){
	file();
	ios::sync_with_stdio(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			a[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if(c<=3){
			ll ans=999999999999999999ll;
			for(int i=0;i<(1<<n);i++){
				ll cnt=0,mx=0;
				for(int j=0;j<n;j++){
					dis[j+1]=999999999999999999ll;
					vis[j+1]=0;
					cnt+=((i>>j)&1);
				}
				if(cnt!=k){
					continue;
				}
				cnt=0;
				msk=i;
				for(int j=1;j<=n;j++){
					if(!vis[j]&&((msk>>j-1)&1)){
						cnt++;
						if(cnt==3){
							break;
						} 
						else{
							dfs(j,0,0);
						}
					}
				}
				if(cnt>2){
					continue;
				}
				for(int j=1;j<=n;j++){
					mx=max(mx,dis[j]);
				}
				ans=min(ans,mx);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
//高二了，依旧无缘 WC。 
//这场最大的失误是 T3 花费了太多时间导致 T4 暴力写完只剩 15 分钟了，多留半小时给 T4 的话反而是很有希望搞到一个接近 300 的分数的。但是都没用了。 
//当然主要的问题应该还是我太菜了，目测 WC 线应该是要过三题的。 
//也许 WC 不是很重要吧，NOIP 还有一次机会，希望不要再这样了……
//过不了二倍队线的话，我这六年，又留下了什么呢？
//宣传群聊 616057779
/*
If I filtered out roses from your view
Will you finally see there is a sword for me too
Wating at every possible path I persue

Hey what if failures today make me a fool
Persistence always pays off in a decade or too
*/
