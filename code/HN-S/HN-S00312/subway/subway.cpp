#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q,w[10081],s,t,vis[10081],ans=1e9;
vector<long long>a[10081];
vector<long long>b[10081];
void D(long long now,long long step){
	if(now==t){
		ans=min(ans,step);
		return;
	}
	for(long long i=0;i<a[now].size();i++){
		long long ne=a[now][i];
		if(!vis[ne]){
			vis[ne]=1;
			D(ne,step+b[now][i]);
			vis[ne]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		long long x,y,x2,y2,wi;
		cin>>x>>y>>x2>>y2;
		wi=y+y2;
		a[x].push_back(y);
		a[y].push_back(x);
		b[x].push_back(wi);
		b[y].push_back(wi);
	}
	for(long long i=1;i<=q;i++){
		ans=1e9;
		memset(vis,0,sizeof(vis));
		cin>>s>>t;
		D(s,0);
		cout<<ans+w[s]+w[t]<<endl;
	}
}
