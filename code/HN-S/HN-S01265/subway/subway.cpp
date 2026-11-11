#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,f[5010][5010],w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=1000010;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int s[k],t[k];
		for(int j=0;j<k;j++){
			cin>>s[j]>>t[j];
			for(int i=0;i<j;i++){
				f[s[j]][s[i]]=min(f[s[j]][s[i]],t[j]+t[i]);
				f[s[i]][s[j]]=f[s[j]][s[i]];
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=k&&j!=k){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				    f[j][i]=f[i][j];
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
