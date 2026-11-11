#include<iostream>
using namespace std;
#define ll long long
int b[1001][1001],tt[1001][1001],sub[1001][1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,a[101],k[101];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			sub[i][j]=sub[j][i]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int p,t;
			cin>>p>>t;
			b[j][p]=1;
			tt[j][p]=t;
		}
	}
	for(int i=1;i<=n;i++){
		int yy=0,gg=0;
		for(int j=1;j<=m;j++){
			if(b[i][j]){
				if(yy!=0){
					sub[yy][j]=sub[j][yy]=tt[i][j]+gg;
				}
				else{
					yy=j;
					gg+=tt[i][j];
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int ww=1;ww<=m;ww++){
				if(sub[i][j]+sub[i][ww]<=sub[j][ww]){
					sub[j][ww]=sub[i][j]+sub[i][ww];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int uu,ui;
		cin>>uu>>ui;
		cout<<sub[uu][ui]+a[uu]+a[ui]<<endl;
	}
	return 0;
}

