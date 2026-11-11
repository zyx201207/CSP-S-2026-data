#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=INT_MAX;
int w[500005],s[500005],t[505][500005],vis[500005]={0};
struct node{
	vector<int> v;
}a[500005];
void solv(int x,int y,int ti){
	vis[x]=1;
	if(x==y){
		if(ti<ans) ans=ti;
		return;
	}
	for(int i=0;i<a[x].v.size();i++){
		if(vis[a[x].v[i]]==0 and ti+t[x][a[x].v[i]]<ans) solv(a[x].v[i],y,ti+t[x][x]+t[x][a[x].v[i]]);
	}
	vis[x]=0;
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>s[j]>>t[i][j];
		for(int j=2;j<=k;j++){
			a[s[j-1]].v.push_back(s[j]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		solv(x,y,w[x]+w[y]);
		cout<<ans<<'\n';
	}
	return 0;
}