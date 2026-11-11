#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
int w[500005];//in or out time
int k[505],ans;//line size
vector<pair<int,int> > e[505];//the station and time of every line
vector<int> a[500005];//the line every station can run
int cntt=INT_MAX;
void dfs(int x,int y,int cnt,int nowline){
	if(y==x){
		cntt=min(cntt,cnt);
		return;
	}
	for(int i=0;i<a[x].size();i++){
		if(a[x][i]==nowline){
			for(int j=0;j<e[nowline].size()-1;j++){
				if(e[nowline][j].first==x){
					dfs(e[nowline][j+1].first,y,cnt,nowline);
					break;
				}
			}
		}
		else{
			//...
		}
	}
}
void solve(){
	int x,y;
	cin>>x>>y;
if(c==7||c==8){
	dfs(x,y,0,a[x][0]);
	cout<<ans+w[x]+w[y]+cntt<<"\n";
}else if(c<=5&&c>0){
	ans=w[x]+w[y];
	for(int i=0;i<a[x].size();i++){
		dfs(x,y,0,a[x][i]);
	}
	cout<<ans<<"\n";
}else{
	cout<<w[x]+w[y]<<"\n";
}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
	cin>>w[i];
}
for(int i=1;i<=n;i++){
	cin>>k[i];
	for(int j=1;j<=k[i];j++){
		int z,x;
		cin>>z>>x;
		e[i].push_back(make_pair(z,x));
		a[z].push_back(i);
	}
}
while(q--){
	solve();
}
	return 0;
}// CSP-S 2026 RP++
