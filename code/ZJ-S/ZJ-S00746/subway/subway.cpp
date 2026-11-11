#include<bits/stdc++.h>
#include<string>
#include<vector>
#define ll long long
using namespace std;
ll c,n,m,d,q,k[500005],a[505][50005],t[505][50005],w[500005];
ll x,y,s;
vector<ll> v[500005];
bool f;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][a[i][j]];
		for(int j=1;j<=k[i];j++) v[a[i][j]].push_back(i);
	}
	if(!f){
		while(q--){
			cin>>x>>y;
			s=INT_MAX;
			for(int i=0;i<v[x].size();i++){
				for(int j=0;j<v[y].size();j++){
					if(v[x][i]==v[y][i]){
						s=min(s,w[x]+t[v[x][i]][x]+t[v[x][i]][y]+w[y]);
					}
				}
			}
			cout<<s<<"\n";
		}
	}
}