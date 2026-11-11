#include<bits/stdc++.h>
#define int long long
#define fileio
//#define opensync
//#define multicase
using namespace std;
int c,n,m,d,q,val[500005],u,v,w,g[505][505],ans;
vector<pair<int,int>> ed[500005];
void INIT(){

}
void MAIN(int CASE){
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>val[i+1];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			g[i][j]=LLONG_MAX/2*(i!=j);
		}
	}
	for(int i=0;i<n;i++){
		cin>>u;
		for(int j=0;j<u;j++){
			cin>>v>>w;
			ed[v].emplace_back(i,w);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<ed[i].size();j++){
			for(int k=0;k<j;k++){
				g[ed[i][k].first][ed[i][j].first]=g[ed[i][j].first][ed[i][k].first]=min(g[ed[i][j].first][ed[i][k].first],ed[i][j].second+ed[i][k].second);
			}
		}
	}
	//这里最有可能超时，但是只有2e8，应该没事
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	} 
	while(q--){
		cin>>u>>v;
		ans=LLONG_MAX/2;
		for(int i=0;i<ed[u].size();i++){
			for(int j=0;j<ed[v].size();j++){
				ans=min(ans,g[ed[u][i].first][ed[v][j].first]+ed[u][i].second+ed[v][j].second);
			}
		}
		cout<<ans+val[u]+val[v]<<'\n';
	} 
}
signed main(){
#ifndef opensync
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
#ifdef fileio
	ifstream fin("subway.in");
	ofstream fout("subway.out");
	auto oldcin=cin.rdbuf(fin.rdbuf());
	auto oldcout=cout.rdbuf(fout.rdbuf());
#endif
	int t=1;
#ifdef multicase
	cin>>t;
#endif
	INIT();
	for(int i=0;i<t;i++){
		MAIN(i);
	}
#ifdef fileio
	cin.rdbuf(oldcin);
	cout.rdbuf(oldcout);
#endif
	return 0;
}
/*
14:47
注意到n,m与一般的定义是相反的 

14:48
神秘爆改最短路？有一个d的限制，这有说法 
这什么神秘题 

14:51
让我分析一下：
这里时间指步行时间 
首先这个w肯定是没用的 
一条地铁线内所有站来回是不需要时间的
如果想从一条地铁线换到另一条地铁线需要花费两条地铁线当前的t
是不是可以把一条地铁线缩成一个点？
有点道理。

15:03
这么简单？
不会读错题了吧？

15:10
思路：
地铁线缩点，原来的点也保留
点在地铁线上就和地铁线的点连边 
权值为 t_{i,u}
询问i->j时跑最短路
得到答案再+w_i+w_j 
问题在于最短路怎么跑
图上有5e5+500个点，但是这5e5个点都最多只有20条边
只对这500个点打APSP?
从复杂度来看是可行的（ 
现在做法分成了两部分：
1.对500个点打APSP
2.已知前面的答案求最短路
1的话直接floyd，这是好做的
2的话O(nq)可过
O(n^2q)是显然的
考虑如何优化。
发现还有一个d之前没有考虑
这个d有什么意义？
保证5e5个点都最多只有d条边
最多只有d条边！
所以询问时直接暴力枚举即可！！！
O(d^2q) 

15:30
去了一趟WC（
floyd会不会被卡？
应该不会，不管了。
开写 

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

15:55
过样例！
测大样例

坏了大样例挂了（ 
测错大样例了（ 

16:00
过大样例，最慢750ms！

注意到T1和T2的大样例都没有给到最后一档
考虑是对拍还是冲T3 

还有2.5h，冲T3！ 
*/ 
