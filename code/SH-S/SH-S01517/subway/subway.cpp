#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll INF=1e18;
int c,n,m,d,q; 
int w[500005];
ll dis[505][505];
struct toln{int dst,id; };
vector<toln> tr[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int a,b,k;
		toln nw;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>b;
			nw.dst=b;
			nw.id=i;
			tr[a].push_back(nw);
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=INF;
		}
	} 
	for(int i=1;i<=m;i++){
		for(int j=0;j<tr[i].size()-1;j++){
			for(int k=j+1;k<tr[i].size();k++){
				dis[tr[i][j].id][tr[i][k].id]=tr[i][j].dst+tr[i][k].dst;
				dis[tr[i][k].id][tr[i][j].id]=tr[i][j].dst+tr[i][k].dst;
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;
		ll ans,cnt=INF;
		cin>>l>>r;
		ans=w[l]+w[r];
		for(int i=0;i<tr[l].size();i++){
			for(int j=0;j<tr[r].size();j++){
				cnt=min(cnt,tr[l][i].dst+tr[r][j].dst+dis[tr[l][i].id][tr[r][j].id]);
			}
		} 
		ans+=cnt;
		cout<<ans<<endl;
	} 
	return 0;
} 
