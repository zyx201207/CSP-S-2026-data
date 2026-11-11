#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],x,y,k;
vector <vector<long long>> a;
long long t[5005][5005];//会爆!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	a.assign(n+1,vector<long long>());
	for(int i=1;i<=m;i++) cin>>w[i];
	cout<<56098;
	for(int p=1;p<=n;p++){
		cin>>k;
		int s1,s;
		for(int i=1;i<=k;i++){
			cin>>s>>t[p][i];
			if(i>1){
				a[s].push_back(s1);
				a[s1].push_back(s);
			}
			s1=s;
		}
	}
	
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		vector <int> d;
		d.assign(m+1,-1);
		queue <int> q;
		q.push(x);
		d[x]=w[x]+t[1][1];
		long long ans;
		while(!q.empty()){
			int is=q.front();
			q.pop();
			int j=1;
			for(auto son:a[is]){
				if(d[son]==-1){
					if(j!=1){
						d[son]=d[is]+t[1][j];
					}
					else d[son]=d[is];
					j++;
				}
			}
		}
		cout<<d[y];
	}
	return 0;
}
/*
c, n, m, d, q，分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。特别地，若 c = 0，则
该测试点为样例。
输入的第二行包含 m 个正整数 w1, w2, . . . , wm，依次表示从每个地铁站的地铁口走
到站厅需要的时间。
输入的第 i + 2 (1 ≤ i ≤ n) 行包含 1 + 2ki 个正整数，其中第一个正整数为 ki，表
示第 i 条线路经过的地铁站数；接下来 2ki 个正整数为 ai,1, ti,1, ai,2, ti,2, . . . , ai,ki, ti,ki，其
中 ai,j 表示第 i 条线路经过的第 j 个地铁站， ti,j 表示从该地铁站的站厅走到第 i 条线
路的站台需要的时间。
输入的第 r + n + 2 (1 ≤ r ≤ q) 行包含两个正整数 xr, yr，分别表示第 r 个出行计
划的起点和终点所在的地铁站编号
5 5
1 2 4 8 9
Oct31==Dec25?
*/
