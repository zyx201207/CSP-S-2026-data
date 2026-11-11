#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
struct node{
	int v,line,ota,otb;
};
int c,n,m,d,q;
int w[maxn];
int k[maxn];
vector<vector<int> >a,t;
vector<node> e[maxn]; 
vector<int> emp;
vector<int> zl;
int st,ed;
int ans;
bool vis[maxn];
void dfs(int x,int fa,int t,int line,int lstup){
	//cout<<x<<" "<<fa<<" "<<line<<" "<<t<<" "<<lstup<<"\n";
	if(x==ed){
		ans=min(ans,t+lstup+w[ed]);
		return;
	}
	for(int i=0;i<e[x].size();i++){
		node y=e[x][i];
		if(y.v==fa||vis[y.v]){
			continue;
		}
		vis[y.v]=1;
		int tt=t;
		if(y.line!=line){
			tt+=y.ota;
			tt+=lstup;
			//cout<<"huancheng:"<<line<<"to"<<y.line<<'\n';
		}
		if(x==st){
			tt+=w[st];
		}
		//cout<<y.v<<" "<<x<<" "<<tt<<" "<<y.line<<" "<<y.otb<<'\n';
		dfs(y.v,x,tt,y.line,y.otb);
		vis[y.v]=0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	emp.push_back(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	a.push_back(emp);
	t.push_back(emp);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a.push_back(emp);
		t.push_back(emp);
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
			if(j>=2){
				e[a[i][j-1]].push_back({a[i][j],i,t[i][j],t[i][j-1]});
				e[a[i][j]].push_back({a[i][j-1],i,t[i][j-1],t[i][j]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		memset(vis,0,sizeof vis);
		cin>>st>>ed;
		ans=1e9;
		dfs(st,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
