#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
int w[500100];
int k[510];
//map<int,int> mp1[510],mp2[500100];
vector<PII> zt[500100],lb[510];
int ltt[510][510];
int ztt[510][510];
int vis[510];
//vector<int> lb[510],ti[510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(ltt,0x3f,sizeof ltt);
	for(int i=1;i<=n;i++){
		ltt[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int k1,k2;
			cin>>k1>>k2;
			lb[i].push_back({k1,k2});
			zt[k1].push_back({i,k2});
		}
	}
	for(int i=1;i<=n;i++){
		priority_queue<PII,vector<PII>,greater<PII> >pq;
		
		for(auto j:lb[i]){
			int u1=j.first,u2=j.second;
			for(auto k:zt[u1]){
				int b1=k.first,b2=k.second;
				pq.push({u2+b2,b1});
			}
		}
		while(!pq.empty()){
			int j1=pq.top().first,j2=pq.top().second;
			pq.pop();
			ltt[i][j2]=min(ltt[i][j2],j1);
		}	
	}
	memset(ztt,0x3f,sizeof ztt);
	for(int i=1;i<=n;i++){
		priority_queue<PII,vector<PII>,greater<PII> > qq;
		memset(vis,0,sizeof vis);
		ztt[i][i]=0;
		qq.push({0,i});
		while(!qq.empty()){
			int h1=qq.top().first;
			int h2=qq.top().second;
			qq.pop();
			if(vis[h2]) continue;
			vis[h2]=1;
			for(int j=1;j<=n;j++){
				if(j==h2) continue;
				if(ztt[i][j]-h1>ltt[h2][j]){
					ztt[i][j]=h1+ltt[h2][j];
					qq.push({ztt[i][j],j});
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int op1,op2;
		cin>>op1>>op2;
		int ans=w[op1]+w[op2];
		int cnt=LONG_LONG_MAX;
		for(auto j:zt[op1]){
			for(auto k:zt[op2]){
				cnt=min(cnt,ztt[j.first][k.first]+j.second+k.second);	
			}
		}
		cout<<cnt+ans<<endl;
	}
	
	return 0;
}

