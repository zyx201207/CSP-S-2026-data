#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+7;
struct node{
	int to;
	int w;
};
int val[MAXN];
int tmp[MAXN];
bool vis[MAXN];
vector <node> adj[MAXN];
int c,n,m,d,q;
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>val[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x;j<=k;j++){
			cin>>x;
			vis[x]=1;
			tmp[j]=x;
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				if(tmp[j]==tmp[l])continue;
				adj[tmp[j]].push_back({tmp[l],0});
				adj[tmp[l]].push_back({tmp[j],0});
			}
		}
	}
	cout<<"QAQ,CCF我恨你";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}