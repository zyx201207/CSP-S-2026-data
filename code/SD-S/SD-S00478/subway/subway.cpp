#include<bits/stdc++.h>
//#define int long long
#define mod 998244353
#define mp make_pair
#define pii pair<int,int> 
#define INF 1e18
#define ll long long
using namespace std;

int c,n,m,d,q;
int k[505],w[500005];
vector<int> a[505],t[505];
vector<pii> in[500005]; 
ll f[505][505];

signed main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			in[x].push_back(mp(i,y));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)f[i][j]=INF;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<k[i];j++){
			int p=a[i][j];//当前站  
			for(auto nxt:in[p]){
				int x=nxt.first,tx=nxt.second;
				//cout<<i<<" "<<p<<" "<<x<<" "<<t[i][j]<<"\n"; 
				f[i][x]=min(f[i][x],1ll*(t[i][j]+tx));
			}
		}
	}
	
	//有用信息就是i<x的部分 
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<f[i][j]<<" ";
//		cout<<"\n";
//	} 
//    for(int i=1;i<=m;i++){
//    	cout<<i<<":"; 
//    	for(auto j:in[i])cout<<j<<" ";
//		cout<<"\n"; 
//	}
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		ll ans=INF;
		for(auto jj:in[u]){
			for(auto kk:in[v]){
				int j=jj.first,jt=jj.second;
				int k=kk.first,kt=kk.second;
				ll now=w[u]+w[v];now+=jt+kt;
				now+=f[j][k];ans=min(ans,now);
				//进站+去第一条地铁+预处理换乘+从最后一条出来+出站 
			}
		}
		cout<<ans<<"\n"; 
	}
}
/*
首先一个很好的性质就是不会使用一辆地铁2次，即使绕的很远
因为要最小化**步行时间** 
所以我们通过一辆地铁可以最小化一个站厅到另一个站厅的时间
而这个值就是tij+tik 
问题转化为，在哪些站使用哪两条地铁

我们可以假设你当前在第i辆地铁上，你想通过换乘走到第j辆地铁上
感觉这是一个很有前途的思路，枚举转移即可 
然后我们对于进站和出站点，枚举进哪个地铁出哪个地铁就行了 

复杂度n^3+md+qd^2 


0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

15:29 大样例都过了，但最后两个点跑了1.3s 
15:44 不准备调了，没跑过去就考完申诉吧，希望ccf机子快一点 
15:53 我去，开O2就好了呀 
*/
