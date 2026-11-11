#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],a[500][5010],t[500][5010],bj[500010],da=0x7fffffff;
void go(int i,int j,int y,int s){
	for(int k=1;k<=a[i][0];k++){
		if(a[i][k]==y){
			da=min(da,s+t[i][k]+w[a[i][k]]);
			return;
		}
	}
	for(int k=1;k<=a[i][0];k++){
		for(int l=1;l<=n;l++){
			for(int o=1;o<=a[l][0];o++){
				if(a[i][k]==a[l][o]&&bj[a[l][o]]==0&&i!=l){
					bj[a[l][o]]=1;
					go(l,o,y,s+t[l][o]+t[i][k]);
					bj[a[l][o]]=0;
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a[i][0]=k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		da=0x7fffffff;
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=a[j][0];k++){
				if(a[j][k]==x){
					bj[a[j][k]]=1;
					go(j,k,y,t[j][k]+w[a[j][k]]);
					bj[a[j][k]]=0;
				}
			}
		}
		cout<<da<<endl;
	}
	return 0;
}
