#include<bits/stdc++.h>
#define lllld long long
#define endl '\n'
using namespace std;
int w[500002],k[502],t[502][500002];
vector<int>staa[500002];//each linethe station has
vector<int>linee[502];//each station the line pass
bool changeablee[500002];
bool vis[500002];
int x,y;
lllld minn;
inline void dfs(int endd,int noww,lllld stepcnt){
	if(noww==endd){
		minn=min(minn,stepcnt);
		return ;
	}
	if(vis[noww]){return;}
	for(int selectlinee:staa[noww]){
		for(int nextt:linee[selectlinee]){
			if(nextt==noww){
				continue;
			}
			if(!changeablee[nextt]&&nextt!=endd)continue;
			vis[noww]=1;
			dfs(endd,nextt,stepcnt+t[selectlinee][noww]+t[selectlinee][nextt]);
			vis[noww]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//each station enter time 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a;
			cin>>a;
			cin>>t[i][a];//i:line j:sta
			linee[i].push_back(a);
			staa[a].push_back(i);
			if(staa[a].size()>=2){
				changeablee[a]=1;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		memset(vis,0,sizeof vis);
		lllld ans=w[x]+w[y];
		minn=0x3f3f3f3f3f3f3f3f;
		dfs(y,x,0);
		cout<<minn+ans<<endl;
		
	}
	return 0;
}
/*
//freopen feropen froopen fropen freeopen luogu 1488910
*/

