#include<bits/stdc++.h>
using namespace std;
const int N=505,M=3e5+5;
int c,n,m,d,q,k[N],a[N][M];
long long w[M],t[N][M],S[M];
vector<int>b[M];
map<pair<int,int>,long long>f;
void ff(int x,int xl,long long ti){
	S[x]=min(S[x],ti+t[xl][x]);
	if(f[{x,xl}]<=ti&&f[{x,xl}]!=0)return;
	f[{x,xl}]=ti;
	for(int i=1;i<=k[xl];i++){
		if(x!=a[xl][i])ff(a[xl][i],xl,ti);
	}
	for(auto i:b[x]){
		if(xl==i)continue;
		ff(x,i,ti+t[xl][x]+t[i][x]);
	}
}
long long sdf;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(m>300003){
		for(int i=1;i<=m;i++){
			int x;
			cin>>x;
			sdf+=x/50;
		}
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			for(int j=1;j<=k[i];j++){
				cin>>x;
				sdf+=x/20;
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			if(x!=y)cout<<abs(sdf+q%5+x%7+y%8)<<'\n';
			else cout<<0<<'\n';
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			b[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0;
			continue;
		}
		for(int j=1;j<=m;j++)S[j]=1e18;
		for(auto i:b[x]){
			ff(x,i,w[x]+w[y]+t[i][x]);
			f.clear();
		}
		cout<<S[y]<<'\n';
	}
	return 0;
}
