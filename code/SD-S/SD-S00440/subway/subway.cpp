//这什么东西??? (CE)
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M];
vector<pair<int,int>> s[M];
//first:线编号,second:站编号 
map<pair<int,int>,int> mp;
int bfs(int x,int y){
	queue<pair<pair<int,int>,int>> q;
	//q.front().second:0-站厅,x:x号线的站台
	q.push({{x,w[x]},0});
	mp[{x,0}]=w[x];
	while(!q.empty()){
		int now=q.front().first.first;
		int tn=q.front().first.second;
		int tp=q.front().second;
		if(tp==0){
			vector<pair<int,int>> lines=s[now];
			for(pair<int,int> i:lines){
				if(mp[{now,i.first}]==0){
					mp[{now,i.first}]=tn+t[i.first][i.second];
					q.push({{now,i.first},tn+t[i.first][i.second]});
				}else{
					if(tn+t[i.first][i.second]<mp[{now,i.first}]){
						mp[{now,i.first}]=tn+t[i.first][i.second];
						q.push({{now,i.first},tn+t[i.first][i.second]});
					}
				}
			}
		}else{
			//A:去站厅,B:去其它站
			//A:
			int line=tp,stid=0;
			for(pair<int,int> i:s[now]){
				if(i.first==line){
					stid=i.second;
					break;
				}
			}
			if(mp[{now,0}]==0){
				mp[{now,0}]=tn+t[line][stid];
				q.push({{now,0},tn+t[line][stid]});
			}else{
				if(tn+t[line][stid]<mp[{now,0}]){
					mp[{now,0}]=tn+t[line][stid];
					q.push({{now,0},tn+t[line][stid]});
				}
			}
			//B:
			for(int i:a[tp]){
				if(mp[{i,tp}]==0){
					mp[{i,tp}]=tn;
					q.push({{i,tp},tn});
				}else{
					if(tn<mp[{i,tp}]){
						mp[{i,tp}]=tn;
						q.push({{i,tp},tn});
					}
				}
			}
		}
	}
	return mp[{y,0}]+w[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			s[a[i][j]].push_back({i,j});
		}
	}
	while(q--){
		mp.clear();
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<"\n";
		}else{
			cout<<bfs(x,y)<<"\n";
		}
		//有想法但写不出来,先写一个BFS吧 
		/*
		想法：
		1.想考虑最短路，但是不知道换乘要怎样处理
		2.想按照优先不换乘的方式， 
			不过需要考虑的问题是两点有直达但是还是不如换乘的情况（见草稿纸），如果没有就比较简单了 
		3.似乎可以考虑一下特殊性质，但是似乎没什么用（还是不知道特殊性质的意义） 
		*/
	}
	return 0;
}
