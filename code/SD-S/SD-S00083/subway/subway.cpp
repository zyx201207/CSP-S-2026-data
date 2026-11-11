#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=5e5+10;
int c,n,m,d,q,w[maxn],k[510];
ll ans[510][510],cnt;
struct node{
	int pos;ll zhi;
};
vector<node> ma[maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ans[i][j]=ans[j][i]=1e17;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			ma[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<ma[i].size();j++){
			for(int k=0;k<j;k++){
				node u=ma[i][j],v=ma[i][k];
				ans[u.pos][v.pos]=min(ans[u.pos][v.pos],u.zhi+v.zhi);
				ans[v.pos][u.pos]=min(ans[v.pos][u.pos],u.zhi+v.zhi);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
				ans[j][i]=ans[i][j];
			}
		}
	}
	while(q--){
		cnt=1e17;
		int l,r;
		cin>>l>>r;
		for(node u:ma[l]){
			for(node v:ma[r]){
				cnt=min(cnt,u.zhi+v.zhi+ans[u.pos][v.pos]);
			}
		}
		cnt+=w[l];cnt+=w[r];
		cout<<cnt<<'\n';
	}
	return 0;
}
