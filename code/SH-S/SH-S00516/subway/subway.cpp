#include<bits/stdc++.h>
using namespace std;
struct side{
	long long index;//这条边所属线路的编号 
	long long to;
	long long down;//这条边从本站站厅到边站台的时间
	long long up;//这条边从to站站台到站厅的时间
	long long k;//这条边的反向边在to站的下标 
};
long long n,m,d;
vector<long long> w;//从入站口到站厅的时间
vector<vector<side>> station;//邻接矩阵
long long ans;
vector<vector<bool>> empty_used;
void dfs(long long now,long long to,vector<vector<bool>>& used,long long num,long long last_index,long long last_up){
	//现在位置，目标位置，已经经过的边，目前为止所花时间，上一条边所属线路的编号，上一条边从现在位置站台到站厅的时间
	if(now==to){
		ans=min(ans,num+last_up);
		return;
	}
	for(long long i=0;i!=station[now].size();i++){
		if(used[now][i])continue;
		if(station[now][i].index!=last_index){
			num+=last_up;
			num+=station[now][i].down;
		}
		used[now][i]=true;
		used[station[now][i].to][station[now][i].k]=true;
		dfs(station[now][i].to,to,used,num,station[now][i].index,station[now][i].up);
		used[now][i]=false;
		used[station[now][i].to][station[now][i].k]=false;
		if(station[now][i].index!=last_index){
			num-=last_up;
			num-=station[now][i].down;
		}
	}
	return;
}
void mian(){
	long long x,y;
	cin>>x>>y;
	x--;
	y--;
	ans=LONG_LONG_MAX;
	vector<vector<bool>> used;
	used=empty_used;
	dfs(x,y,used,0,-1,0);
	cout<<ans+w[x]+w[y]<<endl;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=0;i!=m;i++){
		long long temp;
		cin>>temp;
		w.push_back(temp);
	}
	vector<vector<long long>> a,t;
	for(long long i=0;i!=n;i++){
		long long k;
		cin>>k;
		vector<long long> atemp,ttemp;
		for(long long j=0;j!=k;j++){
			long long tempa,tempt;
			cin>>tempa>>tempt;
			atemp.push_back(tempa-1);
			ttemp.push_back(tempt);
		}
		a.push_back(atemp);
		t.push_back(ttemp);
	}
	station.resize(m,vector<side>(0));
	empty_used.resize(m,vector<bool>(0));
	for(long long i=0;i!=n;i++){
		for(long long j=1;j!=a[i].size();j++){
			side side0,side1;
			side0.down=t[i][j-1];
			side0.index=i;
			side0.to=a[i][j];
			side0.up=t[i][j];
			side0.k=station[a[i][j]].size();
			side1.down=t[i][j];
			side1.index=i;
			side1.to=a[i][j-1];
			side1.up=t[i][j-1];
			side1.k=station[a[i][j-1]].size();
			station[a[i][j-1]].push_back(side0);
			station[a[i][j]].push_back(side1);
			empty_used[a[i][j-1]].push_back(false);
			empty_used[a[i][j]].push_back(false);
		}
	}
	for(long long i=0;i!=q;i++){
		mian();
	}
	return 0;
} 
