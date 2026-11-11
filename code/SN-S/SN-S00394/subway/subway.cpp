#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[1100001];
int a[501][500001],t[501];
int x[500001],y[500001];
int dist[500001];
void dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push(make_pair(0,s));
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		cin>>a[i][k]>>t[i];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++){
		
	} 
}
//呵呵
//有用吗
//[100,0]+0+0+0=[0,100]
//我搞不明白我现在想出T2转化有什么用呢
//silly me
//没关系了
//呵呵
//My Luogu uid is 1659203 欢迎关注
//哈哈哈
//又得等一年
//T1代码消失
//花费3.5h
//T2现在想出来转化了
//最后30min会B了 
//我好腻害 
//CSP-S 2027加油吧
//呵呵 
//快要崩溃了  
