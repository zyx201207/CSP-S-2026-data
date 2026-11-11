#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int maxn=5e5+7;
int w[maxn],l[maxn];
struct Node{
	int a,t;
};
struct node{
	int v,id;
};
vector<node>edge[maxn];
vector<int>dd[maxn];
int s,e,cnt,minl;
int vis[maxn];
void dfs(int u,int id){
	if(u==e){
		minl=min(minl,cnt);
		return ;
	}
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i].v;
		int vid=edge[u][i].id;
//		cout<<u<<" "<<v<<" "<<id<<" "<<vid<<" "<<"\n";
		if(!vis[v]){
			vis[v]=1;
			if(vid!=id) cnt++;
			dfs(v,vid);
			if(vid!=id) cnt--;
			vis[v]=0;
		}
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","r",stdout);
	int c,n,m,d,q,flag1=1,flag2=1,T=-1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>l[i];
		if(l[i]>2) flag1=0;
		Node la,first;
		for(int j=1;j<=l[i];j++){
			int a,t;
			cin>>a>>t;
			dd[a].push_back(i);
			if(j>1) edge[la.a].push_back({a,i});
			else first={a,t};
			if(T==-1) T=t;
			if(T!=t) flag2=0;
			la={a,t};
			if(j==l[i]) edge[a].push_back({first.a,i});
		}
	}
	if(flag2){
		while(q--){
			minl=maxn;
			cin>>s>>e;
			for(int i=0;i<dd[s].size();i++){
				int id=dd[s][i];
				vis[s]=1;
				cnt=1;
				dfs(s,id);
				cnt=1;
				vis[s]=0;
			}
			cout<<w[s]+w[e]+2*minl*T<<"\n";
		}
	}
	return 0;
}
