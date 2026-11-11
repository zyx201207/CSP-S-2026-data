#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000010],dis[2000010],ans,flag;
bool vis[2000010];

void dfs(int s,int tis){
	++flag;
	if(tis<dis[s]){
		dis[s]=tis;
		if(vis[s]==1){
			vis[s]=0;
			ans--;
		}
	}
	else if(tis==dis[s]){
		if(!vis[s]){
			ans++;
			vis[s]=1;
		}
		else{
			ans--;
			vis[s]=0;
		}
	}
	for(int i=1;abs(x[s+i]-x[s])<=d&&s+i<=n;i++){
		dfs(s+i,tis+1);
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(x,0x7f,sizeof(x));
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			memset(dis,0x7f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			dfs(i,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
16:30 休息一下，吃点东西
和旁边的人一块大吃特吃 

16:57 wc，我为什么在看着T4想T3的解法
而且居然还想出来了？

17:38 怎么又报3221225725
栈也太小了

17:50 为什么dfs老是死循溢出啊
查不出来了
又开始报3221225477

小样例报3221225725 
大样例报3221225477
如果有好心人看到了能帮忙查一下啥意思吗
luogu:congcong2012

18:03 查出来了，dfs里把下标带成数值了 
时间复杂度O(2^n)
力竭了
预计8pts 
*/
