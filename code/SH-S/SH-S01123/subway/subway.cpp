#include<bits/stdc++.h>
using namespace std;
int w[500005],k[505],r[100005],bg[500005][25],s[500005],f[505][505];
int a[501][480005],t[501][480005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,sb;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>sb;
			t[i][a[i][j]]=sb;
			bg[a[i][j]][++s[a[i][j]]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=1e9;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(s[a[i][j]]>=2){
				for(int p=1;p<=s[a[i][j]];p++){
					if(bg[a[i][j]][p]!=i){
						f[i][bg[a[i][j]][p]]=min(f[i][bg[a[i][j]][p]], t[i][a[i][j]]+t[bg[a[i][j]][p]][a[i][j]] );
						f[bg[a[i][j]][p]][i]=min(f[i][bg[a[i][j]][p]], t[i][a[i][j]]+t[bg[a[i][j]][p]][a[i][j]] );
					}
				}
			}
		}
	}
	for(int o=1;o<=n;o++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][o]+f[o][j]);
			}
		}
	}
	int x,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(f[i][j]==1e9||i==j)f[i][j]=0;
		}
	}
	for(int i=1;i<=q;i++){
		int rst=1e9;
		cin>>x>>y;
		for(int j=1;j<=s[x];j++){
			for(int u=1;u<=s[y];u++){
				rst=min(rst,f[bg[x][j]][bg[y][u]]);
			}
		}
		for(int j=1;j<=s[x];j++){
			for(int u=1;u<=s[y];u++){
				if(f[bg[x][j]][bg[y][u]]==rst)cout<<rst+w[x]+w[y]+t[bg[x][j]][x]+t[bg[y][u]][y]<<endl;
			}
		}
	} 
	return 0;
}
