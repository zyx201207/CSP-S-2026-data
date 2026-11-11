#include <bits/stdc++.h>
using namespace std;
int c,d,q,n,w[100010],m,k[510],a[510][20010],t[510][20010],p[500010];
int find(int x){
	if(p[x]==x){
		return x;
	}
	p[x]=find(p[x]);
	return p[x];
}
void untie(int x,int y){
	if(p[x]!=p[y]){
		p[x]=find(p[y]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		p[i]=i;
	}
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j==1) continue;
		} 
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=0;
		for(int i=1;i<=k[x];i++){
			if(a[x][i]==y){
				ans+=t[x][i];
			}
		}
		cout<<w[x]+w[y]+ans+t[x][1]<<endl;
	}
	return 0;
}
