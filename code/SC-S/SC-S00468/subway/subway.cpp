#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long cost=0,maxn=INT_MIN;
int sta;
void dfs(int l,int s,vector<vector<int>> &fa,vector<vector<int>> &line,vector<vector<int>> &a,vector<vector<int>> &t,vector<int> &w,long long cost,vector<vector<bool>> vis){
	if(vis[l][s]) return;
	//cout<<l<<' '<<s<<' '<<t[l][s]<<' '<<cost<<' '<<maxn<<endl;
	vis[l][s]=true;
	if(fa[l][s]==s&&s==sta){
		cost+=t[l][s];
		cost+=w[sta];
		maxn=max(cost,maxn);
		return;
	}
	for(int i:line[s]){
		if(fa[i][s]!=0&&i==l){
			dfs(i,fa[i][s],fa,line,a,t,w,cost,vis);
			continue;
		}
		if(fa[i][s]!=0&&i!=l){
			cost+=t[l][s];
			cost+=t[i][s];
			dfs(i,s,fa,line,a,t,w,cost,vis);
			continue;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1,0),an(n+1,0);
	vector<vector<int>> fa(n+1,vector<int>(n+1,0)),co(n+1,vector<int>(n+1,0));
	vector<vector<int>> a,t,line(m+1);
	line.push_back(vector<int>(1,0));
	a.push_back(vector<int>(m+1,0));
	t.push_back(vector<int>(m+1,0));
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		an[i]=k;
		vector<int> a2(m+1,0),t2(m+1,0);
		for(int j=1;j<=k;j++){
			int a1,t1;
			cin>>a1>>t1;
			a2[j]=(a1);
			t2[a1]=(t1);
			line[a1].push_back(i);
		}
		a.push_back(a2);
		t.push_back(t2);
	}
	for(int i=1;i<=n;i++){
		fa[i][a[i][1]]=a[i][1];
		co[i][a[i][1]]=t[i][1];
		auto tmp=a[i];
		for(int j=2;j<=an[i];j++){
			fa[i][a[i][j]]=a[i][j-1];
			co[i][a[i][j]]=t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		maxn=INT_MIN;
		int start,end;
		cin>>start>>end;
		sta=start;
		cost=0;
		cost+=w[end];
		vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
		//t[0][end]=0;
		//for(/*int i=0;i<line[end].size();i++*/auto i:line[end]){
//			dfs();
			dfs(0,end,fa,line,a,t,w,cost,vis);
		//}
		//cout<<co[0][end];
		cout<<maxn<<endl;
	}
}