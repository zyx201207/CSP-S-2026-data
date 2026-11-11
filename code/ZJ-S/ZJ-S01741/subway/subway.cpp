#include<bits/stdc++.h>
using namespace std;
int m,c,n,d,q,x,y,e[10010][10010],a[10010][10010],b[10010][10010],w[10010],k,v[10100],ans=99999;
void dd(int j,int step){
	for(int i=1;i<=m;i++){
		if(e[j][i]!=99999&&v[i]==0){
			if(i==y){
				ans=min(ans,step+e[j][i]);
				return ;
			}
			v[i]=1;
			dd(i,step+e[j][i]);
			v[i]=0;
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=20;i++){
		for(int j=1;j<=20;j++){
			e[i][j]=99999;
		}
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>b[i][j];
		}
		for(int j=1;j<=k;j++){
			for(int t=j+1;t<=k;t++){
				e[a[i][j]][a[i][t]]=min(e[a[i][j]][a[i][t]],b[i][j]+b[i][t]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(e[x][y]!=99999) cout<<e[x][y]+w[x]+w[y];
		else{
			for(int j=1;j<=m;j++){
				if(e[x][j]!=99999){
					v[i]=1;
					dd(j,e[x][j]);
					v[i]=0;
				}
			}
			cout<<w[x]+w[y]+ans<<endl;
		}
	}
	return 0;
}