#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const ll _=500505,N=505;
inline void Min(ll &x,ll y){y<x?x=y:0;}
ll ID,n,m,q,D,t,x,y,w[_],d[N][N],i,j,g;
struct o{ll x,w;};vector<o> a[_];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>ID>>n>>m>>D>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++){
		cin>>t;
		while(t--)cin>>x>>y,a[x].eb(o{i,y});
	}
	memset(d,0x3f,sizeof(d));
	for(i=1;i<=n;i++)d[i][i]=0;
	for(t=1;t<=m;t++){
		for(o i:a[t])for(o j:a[t]){
			Min(d[i.x][j.x],i.w+j.w);
			Min(d[j.x][i.x],j.w+i.w);
		}
	}
	for(g=1;g<=n;g++)for(i=1;i<=n;i++)if(i!=g)
		for(j=1;j<=n;j++)if(j!=i&&j!=g)
			Min(d[i][j],d[i][g]+d[g][j]);
	while(q--){
		cin>>x>>y;t=4e18;
		for(o i:a[x])for(o j:a[y])Min(t,i.w+d[i.x][j.x]+j.w);
		cout<<w[x]+t+w[y]<<'\n';
	}
}
