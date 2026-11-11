#include <bits/stdc++.h>
using namespace std;
int n,m,d,c,ans=0,w[200000],k,dis[505][505],q,a,t;
struct node{
	int v,t;
};
int rd(){
	int k=0;
	int f=1;
	char c;
	c=getchar_unlocked();
	while(c<'0'||c>'9'){
		if(c=='-')    f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar_unlocked();
	}
	return k*f;
}
vector<node> g[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)    w[i]=rd();
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
	    }
	}
	while(q--){
		int r,c;
		cin>>r>>c;
		cout<<w[r]+w[c]<<'\n';
	}
	return 0;
}
