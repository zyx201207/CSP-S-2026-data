//郭昕宇 西安市铁一中学 SN-S00363 
#include<bits/stdc++.h>
using namespace std;
const int MAXM=1000,MAXN=500;
int w[1000+5],t[500+5][1000+5],f[1000+5][1000+5],u[500+5][1000+5],qw[500+5][1000+5];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ccc,n,m,d,q;
	cin>>ccc>>n>>m>>d>>q;
	memset(f,-1,sizeof f);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u[i][j]>>qw[i][j];
			t[i][u[i][j]]=qw[i][j];
		}
		for(int j=1;j<=k;j++){
			for(int l=1;l<=k;l++){
				f[u[i][j]][u[i][l]]=qw[i][j]+qw[i][l];
			}
		}
	}
	for(int i=1;i<=m;i++)f[i][i]=0;
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(1){
		bool flag=0;
		for(int A=1;A<=m;A++){
			for(int B=A+1;B<=m;B++){
				for(int C=A+1;C<=m;C++){
					if(B==C||!f[B][C]||!f[A][B])continue;
					if((f[A][C]==-1||f[A][B]+f[B][C]<f[A][C])&&f[A][B]>=0&&f[B][C]>=0){
						f[A][C]=f[A][B]+f[B][C];
						flag=1;
					}
				}
			}
		}
		if(!flag)break;
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+f[min(x,y)][max(x,y)]<<"\n";
	}
	return 0;
}
