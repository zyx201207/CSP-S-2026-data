#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e15;
const int N=5e5;
int w[N];
int mapp[10001][10001];
vector<int> vec[N];
ll ans=MAXN;
vector<int> line[N];
bool vis[N],visl[N];
void dfs(int s,int e,ll ct,int cl){
	if(ct>ans){
//		cout<<"IT IS TOO LONG IN"<<s<<' '<<e<<' '<<cl<<' '<<ct<<endl;
		return ;
	}
	if(e==s){
//		cout<<"I FINISH MY WORK IN"<<s<<' '<<e<<' '<<cl<<' '<<ct<<endl;
		ans=min(ans,ct+mapp[cl][e]);
		return ;
	}
	for(int i=0;i<line[cl].size();i++){
		int u=line[cl][i];
//		cout<<u<<endl;
//		cout<<"WHERE SHOU I GO"<<endl;
		if(!vis[u]){
//			cout<<"I FIND A WAY IN"<<s<<' '<<e<<' '<<cl<<' '<<ct<<endl;
			vis[u]=1;
			dfs(u,e,ct,cl);
			vis[u]=0;	
		}
	}
	for(int i=0;i<vec[s].size();i++){
		int nl=vec[s][i];
		if(!visl[nl]){
//			cout<<"I FOUND A LINE IN"<<s<<' '<<e<<' '<<cl<<' '<<ct<<endl;
			visl[nl]=1;
			dfs(s,e,ct+mapp[cl][s]+mapp[nl][s],nl);
			visl[nl]=0;
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		for(int j=1;j<=a;j++){
			int u,t;
			//mapp[i][j]    第i条线上到第j站的时间 
			cin>>u>>t;
			vec[u].push_back(i);
			line[i].push_back(u);
			mapp[i][u]=t;
//			cout<<mapp[i][u]<<' '<<t<<' '<<u<<' '<<j<<endl;
		}
	}/*for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<mapp[i][j]<<' '; 
		}cout<<endl;
	}*/
	while(q--){
		int start,end;
		cin>>start>>end;
		vis[start]=1;
		for(int i=0;i<vec[start].size();i++){
			visl[vec[start][i]]=1;
			vis[start]=1;
			dfs(start,end,mapp[start][vec[start][i]],vec[start][i]);
			vis[start]=0;
			visl[vec[start][i]]=0;
		}cout<<ans+w[start]+w[end]<<endl;
	}
	return 0;
}
