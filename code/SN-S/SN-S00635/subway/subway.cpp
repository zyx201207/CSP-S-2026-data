#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],f[505][505],x,y,ans=0x3f3f3f;
bool s[505];
void dfs(int p,int time){
	if(p==y){
		time+=w[y];
		ans=min(ans,time);
		return ;
	}
	if(time+w[y]>ans) return ;
		for(int i=1;i<=m;i++){
			if(f[p][i]&&!s[i]){
				s[i]=1;
				dfs(i,time+f[p][i]);
				s[i]=0;
			}
		}
			 
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout); 
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++) cin>>w[i];
for(int i=1;i<=n;i++){
	int k,a[500005];
	cin>>k;
	for(int j=1;j<=2*k;j++)
		cin>>a[j];
	for(int j=1;j<=2*k;j+=2)
		for(int s=j+2;s<=2*k;s+=2)
			f[a[j]][a[s]]=f[a[s]][a[j]]=a[j+1]+a[s+1];
}
for(int i=1;i<=q;i++){
	cin>>x>>y;
	dfs(x,w[x]);
	cout<<ans<<"\n";
}
	return 0; 
}
