#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=(3e4+10);
const int M=(500);
const int Q=(3000);
int n,m,q,w[N],k[M],s[Q],t[Q],ans[Q],d[N*M],f[N*M],r[M][N],tt[M][N];
struct th{
	int u,w;
	bool operator<(const th &a)const{
		return w>a.w;
	}
};
vector<th>a[N*M];
priority_queue<th>pq;
unordered_map<int,vector<int>>mp;
void dij(int s){
	memset(d,0x3f,sizeof(d));
	memset(f,0,sizeof(f));
	d[s]=0,pq.push({s,0});
	while(pq.size()){
		int rt=pq.top().u;pq.pop();
		if(f[rt]){
			continue;
		}
		f[rt]=1;
		for(auto x:a[rt]){
			if(d[x.u]>d[rt]+x.w){
				d[x.u]=d[rt]+x.w;
				pq.push({x.u,d[x.u]});
			}
		}
	}
}
void bd(){
	for(int i=0;i<=n+1;i++){
		if(i!=0&&i!=(n+1)){
			for(int j=2;j<=k[i];j++){
				a[m*i+r[i][j-1]].push_back({m*i+r[i][j],0});
			}
		}
		for(int j=i+1;j<=n+1;j++){
			for(int k=1;k<=max(::k[i],::k[j]);k++){
				if((i==0||tt[i][r[i][k]])&&(j==n+1||tt[j][r[i][k]])){
					a[m*i+r[i][k]].push_back({m*j+r[i][k],tt[i][r[i][k]]+tt[j][r[i][k]]});
					a[m*j+r[i][k]].push_back({m*i+r[i][k],tt[i][r[i][k]]+tt[j][r[i][k]]});
				}
				if((i==0||tt[i][r[j][k]])&&(j==n+1||tt[j][r[j][k]])){
					a[m*i+r[j][k]].push_back({m*j+r[j][k],tt[i][r[j][k]]+tt[j][r[j][k]]});
					a[m*j+r[j][k]].push_back({m*i+r[j][k],tt[i][r[j][k]]+tt[j][r[j][k]]});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	k[0]=k[n+1]=m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x;j<=k[i];j++){
			cin>>r[i][j]>>x;
			tt[i][r[i][j]]=x;
		}
	}
	bd();
	for(int i=1;i<=q;i++){
		cin>>s[i]>>t[i];
		mp[s[i]].push_back(i);
	}
	for(auto x:mp){
		dij(x.first);
		for(auto y:x.second){
			ans[y]=d[(n+1)*m+t[y]];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<w[s[i]]+w[t[i]]+ans[i]<<"\n";
	}
	return 0;
}