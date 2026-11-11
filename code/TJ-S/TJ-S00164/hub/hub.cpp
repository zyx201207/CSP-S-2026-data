#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int C,T,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;++i){
			cin>>u>>v;
		}
		cout<<k-1<<'\n';
	}
	return 0;
}
/*
	这是我T2的碎碎念（） 

	从x站厅开始，走到某一个线路(a[i][j]==x)(t[i][j])，然后跳到任意a[i][p]
	再从temp=a[i][p]走到temp的站厅(a[i'][j']==temp)，然后再走线路...直到temp==y，直接w出站。 
	也就是，可以从a[i][j]跳到a[i][j']。
	
	j没有用。把这个维度干掉。
	a[i].push_back(p)。然后对于t[i][j]改为t[i][p]。一样的。这样好搜。 
	
	尝试建图：站台->站厅->站台'为点到点的距离。每个点代表一条线路。
	只要知道x, y在哪个点（线路）里就好了。
	求最短路（floyd？） 
	
	但是这样只能说，两条线路中只有一个换乘站。额两个就两条边取最小呗。。。 
	
	开造。 
	
	虽然数不太对，但感觉有点像正解（）这波贪了（）其实应该是可以打特殊性质的，不过我寻思暴力结果把疑似正解给打出来了））
	先打后面暴力吧。一会儿一定会来调。。 
	就是这个报错是意味，虚拟机能运行这来个啥玩意.exe错误很吓人啊。我没见过这个东西。 
	居然是内存开炸了么？？ 
	
	30min，我能否调完这个，成败在此一举。 
	
	我（一种植物），是对的，哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈。 
	（win）大测试点编译会报错？什么情况？
	terminate called after throwing an instance of 'std::bad_alloc'
 	 what():  std::bad_alloc
 	大数据过不了。为什么？
	linux报错core什么的，吓哭了我干啥了。
	
	结束了。希望评测机放过我（双手合十） 
*/ 
