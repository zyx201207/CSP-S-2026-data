#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
namespace solve1{
	int f[305][305];
	int g[305][305];
	int a[305];
	void solve(){
		int n, d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		memset(f, 0x3f, sizeof f);
		for(int i=1;i<=n;i++)
			f[i][i]=0, g[i][i]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(abs(a[i]-a[j])<=d)
					f[i][j]=1, g[i][j]=1;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j || i==k || k==j) continue;
					if(f[i][j]>f[i][k]+f[k][j])
						f[i][j]=f[i][k]+f[k][j], g[i][j]=g[i][k]*g[k][j];
					else if(f[i][j]==f[i][k]+f[k][j])
						g[i][j]+=g[i][k]*g[k][j];
				}
			}
		}
		int s=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				s+=g[i][j]==2;
		cout<<s<<'\n';
	}
}
namespace solve2{
	void solve(){
		int n, d;
		cin>>n>>d;
		int k=0;
		cin>>k;
		if(n==1){
			cout<<"0\n";
			return;
		}
		int xrz_like_moya=0;
		cin>>xrz_like_moya;
		k=xrz_like_moya-k;
		for(int i=3;i<=n;i++)
			cin>>xrz_like_moya;
		int s=0;
		if(d<k){
			cout<<"0\n";
			return;
		}
		for(int i=1;i<n;i++)
			if(i%(d/k)==1)
				s+=n-i;
		cout<<s<<'\n';
	}
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin>>c>>t;
	while(t--){
		if(c==1 || c==2 || c==0) solve1::solve();
		else if(c==11 || c==12) solve2::solve();
		else cout<<"郡猫雅猫长长九九！！！\n";
	}
	return 0;
}
/*
首先注意到从一个岛能到的地方一定是一段区间
所以我们可以预处理出来那一段区间
这是O(n log n)的
先考虑特殊性质A 
这个性质是固定了最短路长度
假设相隔x个岛屿
则最短路为x/(d/w)
如果最短路为1，不可能
如果x%(d/w)==0则不可能
如果x%(d/w)==1则是对的
如果x%(d/w)>1则不可能
综上，我们解决了这道题                                                                                               的A性质， 
好吧皮一下
接下来想想他给了我们什么启发（没有启发/bushi
那就是我们可以知道每一个“双径岛屿对”是由一堆“单径岛屿对”加上一个非最小值组成
然后我力竭了
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
不！！！！！！ 
*/
