#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ti=1e9,vis[500005]={};
int w[500005],k[500005],a[501][500005],t[501][500005],x,y;
int f[500005][501],len[500005]={};
int saet[500005][501]={};
void clean(){
	for(int i=1;i<=m;i++) vis[i]=0;
}
void dp(int p,int s){
	if (p==y){
		ti=min(ti,s);
	}
	for(int i=1;i<=len[p];i++){
		for(int j=1;j<=k[i];j++){
			int sex=a[f[p][i]][j];
			if (sex!=p&&vis[sex]==0){
				int qe=s+t[i][j]+saet[p][i];
				vis[sex]=1;
				dp(sex,qe);
				vis[sex]=0;
			} 
		}
	}
}
int main(){
	freopen("subway.in","r",stdin); 
    freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			f[a[i][j]][++len[a[i][j]]]=i;
			saet[a[i][j]][len[a[i][j]]]=t[i][j];
		}
	}
	int times[100005]={};
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		dp(x,w[x]+w[y]);
		clean();
		times[i]=ti;
	}
	for(int i=1;i<=q;i++) cout<<times[i]<<"\n";
	fclose(stdin);
    fclose(stdout);
	return 0;
}
