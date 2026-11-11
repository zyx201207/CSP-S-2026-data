#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,t;
int n,k;
int a[N];
int ans;
int sum;
bool f[N];
int mi=INT_MAX;
void dfs(int now,int v,int dep){
	if(now==v){
		mi=min(mi,dep);
		return;
	}
	for(int i=1;i<=n;i++){
		if(now==i) continue;
		if(abs(a[now]-a[i])<=k&&f[i]==0){
			f[i]=1;
			dfs(i,v,dep+1);
			f[i]=0;
		}
	}
}
void dfs1(int now,int v,int dep){
	if(now==v){
		if(dep==mi) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(now==i) continue;
		if(abs(a[now]-a[i])<=k&&f[i]==0){
			f[i]=1;
			dfs1(i,v,dep+1);
			f[i]=0;
		}
	}
}
void solve(){
	cin>>n>>k;
	ans=0;
	sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=0;
			mi=INT_MAX;
			for(int k=1;k<=n;k++){
				f[k]=0;
			}
			dfs(i,j,0);
			dfs1(i,j,0);
			if(ans==2){
//				cout<<i<<' '<<j<<endl;
				sum++;
			}
		}
	}
	cout<<sum<<endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
感觉T3比T2可做
额，两种情况
1.两座海岛可以直接飞到，中间有且仅有一座岛屿
三座岛屿随机抽取两座都是~岛屿
2.两座海岛不能直接飞到，但是中间有且仅有两座岛屿
路径是1-2-4或者1-3-4
同样，随机抽取两座岛屿都是~岛屿
n^3暴力是容易的
但这是废物的思维！我要n^2甚至是O(n)解法！
不对劲没这么简单
万一两个岛屿不可直接到达，然后中间还有三座岛呢？
哦哦哦没事了要长度最短啊
坏了现在连废物的思维都没有了呃呃呃
原来长度是指次数啊，我以为真的指长度呢
唐了
我就知道咋可能这么简单
那没办法了，拼个8分的暴力吧
大样例测不了，无法验证正确性
算了直接交吧，尽人事看天命
*/
/*
文明与道德被埋葬在黎明前，踽行于无止境的风雪之中，伊塔库亚早已忘了自己为谁守夜
*/