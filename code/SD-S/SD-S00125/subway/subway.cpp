#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5,MAXN=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k,w[M],a[M],t[M];
int s=MAXN,t2[3][M],b[3][M];
void sol(){
	int f[405][405];
	memset(f,0x3f3f,sizeof f);
	for(int i=1;i<=m;i++) f[i][i]=0;
	while(n--){
		cin>>k;
		for(int i=1;i<=k;i++) cin>>a[i]>>t[i];
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++)
				if(i!=j) f[a[i]][a[j]]=min(t[i]+t[j],f[a[i]][a[j]]);
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
				if(f[i][k]!=MAXN&&f[k][j]!=MAXN) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<"\n";
	}
}
void work(){
	memset(b,0,sizeof b);
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j];
			cin>>t2[i][a[j]];
			b[i][a[j]]=1;
		}
	} 
	for(int i=1;i<=m;i++)
		if(b[1][i]&&b[2][i]) s=min(s,t2[1][i]+t2[2][i]);
	while(q--){
		int x,y,c=MAXN;
		cin>>x>>y;
		if(n==1) cout<<w[x]+w[y]<<"\n";
		if(b[1][x]&&b[1][y]) c=min(c,t2[1][x]+t2[1][y]);
		if(b[2][x]&&b[2][y]) c=min(c,t2[2][x]+t2[2][y]);
		if((b[1][x]&&b[1][y])||(b[2][x]&&b[2][y])) cout<<w[x]+w[y]+c<<"\n";
		else {
			if(b[1][x]) cout<<w[x]+w[y]+s+t2[1][x]+t2[2][y]<<"\n"; 
			else cout<<w[x]+w[y]+s+t2[2][x]+t2[1][y]<<"\n"; 
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(m<=400) sol();
	else if(n<=2) work();
	return 0; 
}
