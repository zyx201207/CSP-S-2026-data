#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=507;
const int M=5e5+3;

int c,n,m,d,q;
int w[M];
int k[N];
vector<vector<int> > a;
vector<vector<int> > t;
int x,y;

vector<int> station[M];
struct str{
	int fs,ss,ln;
};
map<pair<int,int>,int> db;
int visl[N],visp[M];
bool fun(int sta,int line){
	for(auto e:station[sta]){
		if(e==line) return true;
	} 
	return false;
}
int query(int x,int y,int ln){
	queue<str> q;
	memset(visp,0,sizeof(visp));
	memset(visl,0,sizeof(visl));
	q.push({x,0,ln});
	visp[x]=true;
	visl[ln]=true;
//	cerr<<"RE check 1\n";
	while(!q.empty()){
		str now=q.front();
		q.pop();
//		cerr<<"DEBUG: "<<now.fs<<' '<<now.ss<<' '<<now.ln<<'\n';
		if(now.fs==y){
			return now.ss+t[now.ln][db[{now.fs,now.ln}]];
		}

		if(station[now.fs].size()>1){
			for(auto e:station[now.fs]){
				if(e!=now.ln&&!visl[e]){
					visl[e]=true;
					q.push({now.fs,now.ss+t[now.ln][db[{now.fs,now.ln}]]+t[e][db[{now.fs,e}]],e});
				}
			}
		}

		int d=db[{now.fs,now.ln}];
		for(int i=1;i<=k[now.ln];i++){
			if(i==d) continue;
			if(station[a[now.ln][i]].size()>1||fun(y,now.ln)){
				q.push({a[now.ln][i],now.ss,now.ln});
				visp[a[now.ln][i]]=true;
			}
		}
	}
	return 0;
}

signed main(){
//	int start=clock();
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	a.resize(n+1);
	t.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			station[a[i][j]].push_back(i);
			db[{a[i][j],i}]=j;
		}
	}
//	for(int i=1;i<=m;i++){
//		for(auto e:station[i]){
//			cout<<e<<' ';
//		}
//		cout<<'\n';
//	}
	while(q--){
		cin>>x>>y;
		int lx=station[x].size();
		int ly=station[y].size();
		int ans=0x3f3f3f3f;
		for(int i=0;i<lx;i++){
			int e=station[x][i];
			for(int j=0;j<ly;j++){
				int f=station[y][j];
				if(e==f){
					cout<<w[x]+w[y]+t[e][db[{x,e}]]+t[f][db[{y,f}]]<<'\n';
					goto ed;
				}
			}
		}
//		cerr<<"miao\n";
		for(auto e:station[x]){
			ans=min(ans,query(x,y,e))+t[e][db[{x,e}]];
		}
		cout<<ans+w[x]+w[y]<<'\n';
		ed:;
	}
//	int end=clock();
//	cerr<<"running time: "<<end-start;
	return 0;
}