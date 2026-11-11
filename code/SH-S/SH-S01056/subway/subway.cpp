#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int a[51][301][51][301]={};
int s[1001][1001]={},l[1001][1001]={};
int b[1001]={};
int t[1001]={};
int z[1001][1001]={};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
		for(int j=1;j<=t[i];j++){
			cin>>s[i][j]>>l[i][j];
			z[s[i][j]][j]=i;
		}
		for(int j=1;j<=t[i];j++){
			for(int k=1;k<=t[i];k++){
				if(j!=k){
					a[s[i][j]][i][s[i][k]][i]=l[i][j]+l[i][k];
					a[s[i][k]][i][s[i][j]][i]=l[i][j]+l[i][k];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=t[i];j++){
			for(int k=1;k<=n;k++){
				for(int o=1;o<=t[k];o++){
					if(s[i][j]==s[k][o]&&i!=k){
						a[s[i][j]][i][s[k][o]][k]=l[i][j]+l[k][o];
						a[s[i][j]][k][s[k][o]][i]=l[i][j]+l[k][o];
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=n;k++){
				for(int o=1;o<=n;o++){
					if(a[i][k][j][k]!=0&&a[j][k][j][o]!=0&&i!=j&&k!=o){
						if(a[i][k][j][o]==0)a[i][k][j][o]=a[i][k][j][k]+a[j][k][j][o]-l[k][z[j][k]];
						else a[i][k][j][o]=min(a[i][k][j][o],a[i][k][j][k]+a[j][k][j][o]-l[k][z[j][k]]);
						a[j][o][i][k]=a[i][k][j][o];
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				for(int o=1;o<=n;o++){
					for(int u=1;u<=n;u++){
						if(a[i][o][j][u]!=0&&a[j][u][k][u]!=0&&i!=j&&i!=k&&j!=k&&o!=u){
							if(a[i][o][k][u]==0)a[i][o][k][u]=a[i][o][j][u]+a[j][u][k][u]-l[u][z[j][u]];
							else a[i][o][k][u]=min(a[i][o][k][u],a[i][o][j][u]+a[j][u][k][u]-l[u][z[j][u]]);
							a[k][u][i][o]=a[i][o][k][u];
						}
					}
				}
			}
		}
	}

	int st,ed;
	for(int i=1;i<=q;i++){
		cin>>st>>ed;
		int ans=999999;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[st][j][ed][k]!=0){
					ans=min(ans,a[st][j][ed][k]);
				}
			}
		}
		cout<<ans+b[st]+b[ed]<<endl;
	}
	//cout<<a[1][1][2][1]<<" "<<a[2][1][2][2]<<" "<<a[2][2][3][2]<<" "<<a[1][1][2][2]<<" "<<a[1][1][3][2]<<" "<<l[1][2]<<" "<<l[1][z[2][1]];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
