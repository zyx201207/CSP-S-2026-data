#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pil pair<int,ll>
#define ver first
#define tme second
char c;
ll read(){
	ll f=1,a=0;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a*=10;
		a+=c-'0';
		c=getchar();
	}
	return f*a;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,d,q;
	read();n=read();m=read();d=read();q=read();
	vector<ll> w(m+1);
	vector<vector<int>> st(n+1);
	vector<vector<pil>> t(m+1);
	vector<vector<ll>> dis(n+1,vector<ll>(n+1,LLONG_MAX>>1));
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int p;
		p=read();
		st[i].resize(p);
		for(int j=0;j<p;j++){
			int f;
			st[i][j]=read();f=read();
			t[st[i][j]].push_back({i,f});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<t[i].size();j++)
			for(int k=j+1;k<t[i].size();k++){
				int jv=t[i][j].ver,kv=t[i][k].ver;
				dis[kv][jv]=dis[jv][kv]=min(dis[jv][kv],t[i][j].tme+t[i][k].tme);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[k][j]=dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
	while(q--){
		int x,y;
		ll mn=LLONG_MAX;
		x=read();y=read();
		for(pil i:t[x])
			for(pil j:t[y])
				mn=min(mn,dis[i.ver][j.ver]+i.tme+j.tme);
		cout<<w[x]+mn+w[y]<<'\n';
	}
}