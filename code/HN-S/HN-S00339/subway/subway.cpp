#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
int c,n,m,d,q;
int w[MAXN];
int f[5000][5000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	memset(f,0x3f3f3f3f,sizeof(f));
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			f[a][m+i]=t;
		    f[m+i][a]=t;
	    }
	}
	for(int k=1;k<=m+n;k++){
		for(int i=1;i<=m+n;i++){
			for(int j=1;j<=m+n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1,b,e;i<=q;i++){
		cin>>b>>e;
		cout<<w[b]+f[b][e]+w[e]<<endl;
	}
	return 0;
} 
