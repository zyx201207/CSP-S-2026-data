#include<bits/stdc++.h>
using namespace std;
struct node{
	long long xh;
	long long w;
	long long lxw;
}s[500005];

long long n,m,d,q,x,y,ans;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c;
	cin>>c>>n>>m>>d>>q;
	node lx[n+1][m+1]={};
	for(int i=1;i<=m;i++){
		cin>>s[i].w;
		s[i].xh=i;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>lx[i][j].xh>>lx[i][j].lxw;
		}
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		ans+=s[x].w+s[y].w;
		
		cout<<ans<<"\n";
	}
	return 0;
}
