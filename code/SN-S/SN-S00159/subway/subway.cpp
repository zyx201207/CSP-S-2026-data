#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010];
int k,a[500010],t[500010];
int x,y;
struct z{
	int e,to;
};
vector<z>g[500010];
int ans=1e9;
void dfs(int pos,int f,int cnt){
	if(pos==f){
		ans=min(ans,cnt);
		return;
	}
	for(z s:g[pos]){
		dfs(s.e,f,cnt+s.to);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)cin>>a[j]>>t[j];
		for(int j=1;j<k;j++){
			for(int kk=j+1;kk<=k;kk++){
				g[a[j]].push_back({a[kk],t[j]+t[kk]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		dfs(x,y,0);
		cout<<w[x]+w[y]+ans<<'\n';
	}
}
//gugugaga gugugaga gugugaga!!!
