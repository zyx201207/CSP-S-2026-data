#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int a[N];
int c,n,m,d,q;
int vis[N*2];
long long dist[N*4];
vector<pair<int,pair<int,int> > > v[N*2];
vector<pair<int,int> > vv[N*2];

int dj2(int st,int en){
	for(int i=1;i<=m;i++)dist[i]=LONG_LONG_MAX;
	priority_queue<int,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,st});
	
	while(!q.empty()){
		int x=q.top().second,price=q.top().first;
		q.pop();
		if(vis[x]==n+1)continue;
		vis[x]++;
//		cout<<x<<" "<<en+m<<"\n";
		if(x==en)return price;
		for(int i=0;i<v[x].size();i++){
			int to=vv[x][i].first,pri=vv[x][i].second;
//			cout<<x<<" "<<to<<" "<<pri<<" "<<price<<"\n";
//			cout<<last_<<" "<<id_<<"\n";
			if(dist[to]>price+pri){dist[to]=price+pri;q.push({dist[to],to});}
		}
	}
	return 0;
}

int dj(int st,int en){
	for(int i=1;i<=m*2;i++)vis[i]=0;
	priority_queue<int,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
	q.push({0,{st,0}});
	
	while(!q.empty()){
		int x=q.top().second.first,price=q.top().first,last_=q.top().second.second;
		q.pop();
		if(vis[x]==n+1)continue;
		vis[x]++;
//		cout<<x<<" "<<en+m<<"\n";
		if(x==en+m)return price;
		for(int i=0;i<v[x].size();i++){
			int to=v[x][i].first,pri=v[x][i].second.first,id_=v[x][i].second.second;
//			cout<<x<<" "<<to<<" "<<pri<<" "<<price<<"\n";
//			cout<<last_<<" "<<id_<<"\n";
			if(last_!=id_&&x<=m)continue;
			if(x>m&&last_==id_)continue;
			if(x>m)q.push({price+pri,{to,id_}});
			else q.push({price+pri,{to,id_}});
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n<=5){
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			int las,x;
			for(int j=1;j<=k;j++){
				int now_,num_;cin>>now_>>num_;
				if(j!=1)v[las].push_back({now_,{0,i}});
				v[now_].push_back({m+now_,{num_,i}});
				v[m+now_].push_back({now_,{num_,i}});
				las=now_,x=num_;
			}
		}
		//	for(int i=1;i<=m;i++)for(int j=0;j<v[i].size();j++)cout<<i<<" "<<v[i][j].first<<" "<<v[i][j].second<<"\n";
		while(q--){
			int st,en;cin>>st>>en;
			int ans=dj(st+m,en);
			cout<<ans+a[en]+a[st]<<"\n";
		}
	}else{
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			int k;cin>>k;
			int las,x;
			for(int j=1;j<=k;j++){
				int now_,num_;cin>>now_>>num_;
				if(j!=1)vv[las].push_back({now_,x+num_});
				las=now_,x=num_;
			}
		}
		//	for(int i=1;i<=m;i++)for(int j=0;j<v[i].size();j++)cout<<i<<" "<<v[i][j].first<<" "<<v[i][j].second<<"\n";
		while(q--){
			int st,en;cin>>st>>en;
			int ans=dj2(st,en);
			cout<<ans+a[en]+a[st]<<"\n";
		}
	}
	
	//	for(int i=1;i<=m;i++){
	//		for(int j=0;j<v[i].size();j++){
	//			cout<<i<<" "<<v[i][j].first<<" "<<v[i][j].second.first<<" "<<v[i][j].second.second<<"\n";
	//		}
	//		cout<<"\n";
	//	}
	
	
	return 0;
}
/*
15:13

15:39

16:42 guo yang li

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

*/
