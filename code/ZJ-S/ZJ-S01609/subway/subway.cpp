#include<bits/stdc++.h>
#define int long long
using namespace std;
int _,c,m,n,D,q,w[500010],cn[500010];
int d[500010][25],t[500010][25],dd[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>m>>n>>D>>q;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=m;i++){
    	int cnt,x,y;
    	cin>>cnt;
    	for(int j=1;j<=cnt;j++){
    		cin>>x>>y;
    		d[x][++cn[x]]=y;
    		t[x][cn[x]]=i;
		}
	}
	memset(dd,0x3f,sizeof dd);
	for(int i=1;i<=m;i++) dd[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cn[i];j++){
			for(int k=j+1;k<=cn[i];k++){
				dd[t[i][j]][t[i][k]]=min(dd[t[i][j]][t[i][k]],d[i][j]+d[i][k]);
				dd[t[i][k]][t[i][j]]=min(dd[t[i][k]][t[i][j]],d[i][j]+d[i][k]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dd[i][j]=min(dd[i][j],dd[i][k]+dd[j][k]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=cn[x];i++) for(int j=1;j<=cn[y];j++) ans=min(ans,d[x][i]+d[y][j]+dd[t[x][i]][t[y][j]]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
    return 0^_^0;
}
/*
>1e8?
computer are fast these day.
suo yi wo jue de wo neng guo
I think neng guo = 1=
15:57 o bububububu zhe ge hao jia.
16:04 zen me yang li 2 jia le
o hai shi Floyd da lao
16:12 zen me hai yao longlong a
dayangli 0.7s ke yi guo
ying gai AC ba
*/