#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,t,w1[500500],w3,a,x2,y,k;
int w2[550][500500],w[550][550],dx[2000][2000];
int check(long long a,long long b){
	int _min=0x3f3f3f;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int z=1;z<=m;z++){
				_min=min(_min,w2[i][a]+w2[j][b]+dx[i][j]);
			}
		} 
	}
	return _min;
}
int main(){
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(w2,0x3f3f3f,sizeof w2);
    memset(w,0x3f3f3f,sizeof w);
    memset(dx,0x3f3f3f,sizeof dx);
    for(int i=1;i<=n;i++){
    		w[i][i]=0;
	}
    for(int i=1;i<=m;i++) cin>>w1[i];
    for(int i=1;i<=n;i++){
    	cin>>k;
    	for(int j=1;j<=k;j++){
    		cin>>a>>w3;
    		w2[i][a]=w3;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			for(int z=1;z<=n;z++){
				dx[i][j]=min(dx[i][j],w2[i][z]+w2[j][z]);
				dx[j][i]=dx[i][j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			w[i][j]=min(check(i,j),w[i][j]);
			w[j][i]=w[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x2>>y;
		cout<<w1[x2]+w1[y]+w[x2][y]<<endl;
	}
	return 0;
}
