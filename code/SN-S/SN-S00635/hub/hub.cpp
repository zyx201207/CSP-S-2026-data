#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],f[505][505],x,y,ans=0x3f3f3f;
void dfs(int p,int time){
	if(p==y){
		time+=w[y];
		if(time<ans) ans=time;
		return ;
	}
	if(time+w[y]>ans) return ;
		for(int i=1;i<=m;i++)
			if(f[p][i]) dfs(i,time+f[p][i]);
}
int main(){
freopen("subway1.in","r",stdin);
freopen("subway1.out","w",stdout); 
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++) cin>>w[i];
for(int i=1;i<=n;i++){
	int k,a[500005];
	cin>>k;
	for(int j=1;j<=2*k;j++){
		cin>>a[j];
		if(j>=4&&(j%2==0)){
			f[j-1][j-3]=f[j-3][j-1]=a[j]+a[j-2];
		}
	}
}
for(int i=1;i<=q;i++){
	cin>>x>>y;
	dfs(x,w[x]);
	cout<<ans<<"\n";
}
	return 0; 
}
