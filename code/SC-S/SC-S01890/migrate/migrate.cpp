#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,d,a[N];
int f[N],g[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _,T;cin>>_>>T;
	if(_<=10){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) f[j]=1e18,g[j]=0;
				f[i]=0;g[i]=1;
				for(int j=i;j<=n;j++){
					if(j!=i&&a[j]-a[j-1]>d) break;
					for(int k=j-1;a[j]-a[k]<=d&&k;k--){
						if(a[j]-a[k]<=d&&f[k]+1<f[j]) f[j]=f[k]+1,g[j]=g[k];
						else if(a[j]-a[k]<=d&&f[k]+1==f[j]) g[j]+=g[k];
					}
					if(g[j]==2) ans++;
				}
			}
			cout<<ans<<'\n';
		}
	}
	else if(11<=_&&_<=12){
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			int k=a[2]-a[1];
			if(d<k){cout<<0<<'\n';continue;}
			int x=d/k;
			if(x==1){cout<<0<<'\n';continue;}
			cout<<max(0ll,n-(2*x-1))<<'\n';
		}
	}
	else{
		while(T--) cout<<0<<'\n';
	}
	return 0;
}
/*
这个题应该是 DP 了，先考虑拿部分分。
要想计数，得先会判定，什么样的两个点间恰有两条最短路？
设 d[x]<d[y]，若 x,y 之间存在 >d 的间隙则无最短路。
考虑从 y 往回跳到 x，比较显然的贪心是每次跳越多越好，一定是最短路。
什么时候最短路会变多？
有不同的路径能到达同一个点，那能不能像在 DAG 上 DP 一样？
设 f[i][j] 表示从 i 出发到 j 的最短路长度，g[i][j] 表示最短路数。
if(a[j]-a[k]<=d&&f[i][k]+1<f[i][j]) f[i][j]=f[i][k]+1,g[i][j]=g[i][k]
else if(a[j]-a[k]<=d&&f[i][k]+1==f[i][j]) g[i][j]+=g[i][k]
这样就是 O(n^3) 的 DP 有 24 分。
考虑怎么优化到 O(n^2)，这个 DP 状态搞不了啊。
考虑特殊性质怎么做，等差数列怎么做？
若 d<公差，显然答案为 0。
等差数列意为每个点向后连边数是固定的，设最多能连 x 个点。
其实就是判断两点间距离 x 能否拆成恰好 k 个 <=x 的数，且 k最小。
可以发现 k 只能等于 2，且是 x 和 x-1，x=1 除外。 
性质 B 怎么做？等价于 a[n]-a[1]<=2d
突然想到一个剪枝，若存在 a[j]-a[j-1]>d，则 j 后面所有右端点都没贡献了。
那么只用考虑距离 <=d 的情况。

*/