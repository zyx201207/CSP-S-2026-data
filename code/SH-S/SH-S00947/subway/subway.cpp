#include<cstdio>	//n线路数,m站数,d最长过站，q计划数 
#include<vector> 
#include<iostream>
using namespace std;
vector<vector<int> >time;
vector<vector<pair<int,int> > >station,train;
vector<int> w;
int n,m,d,q;
vector<bool> done,doing;
void dfs(int start,int timing,int father,int root,int route){
	doing[start]=1;
	if(root!=0 && timing>time[root][start])	return;
	time[root][start]=timing;
	for(int i=0,now;i<station[start].size();i++){	//第i条线路 
		cout<<i<<endl; 
		if(station[start][i].first!=route)timing+=station[start][i].second;
		for(int j=0;j<train[station[start][i].first].size();j++){
			if(train[station[start][i].first][j].first==start || train[station[start][i].first][j].first==father || train[station[start][i].first][j].first==root)
				continue;
			if(doing[train[station[start][i].first][j].first])	continue;
			dfs(train[station[start][i].first][j].first,timing,start,root,station[start][i].first);
		}
		if(station[start][i].first!=route)timing-=station[start][i].second;
	}
	doing[start]=0;
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&n,&m,&d,&q);
	time.resize(m+1);doing.resize(m+1);
	for(int i=1;i<=m;i++)	time[i].resize(m+1); 
	w.resize(m+1);
	done.resize(m+1);
	train.resize(n+1);
	station.resize(m+1);
	for(int i=1;i<=n;i++)	train[i].clear();
	for(int i=1;i<=m;i++)	station[i].clear();
	for(int i=1;i<=m;i++)	scanf("%d",&w[i]);	//进出站时间 
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,p,t;j<=k;j++){
			scanf("%d%d",&p,&t);
			train[i].push_back({p,t});
			station[p].clear();
			station[p].push_back({i,t});	//?
		}
	}//有最高效站数为线路数*最长过站 
	for(int i=1,a,b;i<=q;i++){
		scanf("%d%d",&a,&b);
		if(a==b){
			putchar('0');
			putchar('\n');
			continue;
		}
		if(done[a]){
			printf("%d\n",time[a][b]+w[a]+w[b]);
			continue;
		}
		if(done[b]){
			printf("%d\n",time[b][a]+w[a]+w[b]);
			continue;
		}
		dfs(a,0,a,a,0);
		done[a]=1;
		printf("%d\n",time[a][b]+w[a]+w[b]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
