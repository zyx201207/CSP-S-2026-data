#include<bits/stdc++.h>
#define ll long long
#define p pair<int,int>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,x[N],y[N],w[N],k[N];//a[600][N],w[600][N]
struct node{
	ll u,t,idl,id[25];
};
vector<node>v[N];
ll b(ll s,ll e){
	priority_queue<p,vector<p>,greater<p> >q;
	q.push({w[s],s});
	return 1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];//,v[i].idl=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];ll a,t,a1,t1;
		cin>>a1>>t1;
	//	v[a].push_back(t);
		for(int j=1;j<k[i];j++){
			cin>>a>>t;
			v[a].push_back({a1,t});
			v[a][v[a].size()-1].id[++v[a][v[a].size()-1].idl]=i;
			v[a1].push_back({a,t1});
			v[a1][v[a1].size()-1].id[++v[a1][v[a1].size()-1].idl]=i;
			a1=a,t1=t;
		//	cin>>a[i][j]>>t[i][j];
		}
	}for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	
	
	return 0;
} 
