#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10;
ll c,n,m,d,q,w[N],k,a[N],t[N],rx,ry,dis[N][N];
struct tw{ll f,s;};
vector<tw>f[N];
ll zdl(){
	memset(dis,0x3f,sizeof(dis));
	queue<tw>q;
	q.push({rx,1});
	dis[rx][rx]=0;
	while(!q.empty()){
		auto x=q.front();
		q.pop();
		if(x.s<m){
		for(auto y:f[x.f]){
			dis[rx][y.f]=min(dis[rx][y.f],dis[rx][x.f]+y.s);
			q.push({y.f,x.s+1});}}}
	return dis[rx][ry];}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			for(int l=1;l<j;l++){
				f[a[j]].push_back({a[l],t[j]+t[l]});
				f[a[l]].push_back({a[j],t[j]+t[l]});}}}
	while(q--){
		cin>>rx>>ry;
		cout<<w[rx]+zdl()+w[ry]<<'\n';}
	return 0;}
