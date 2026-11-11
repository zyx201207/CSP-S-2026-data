#include <bits/stdc++.h>
using namespace std;

long long c,n,m,d,q;
long long a[100100],b[100100],e[100100][100100],t[100100][100100],xq[100100],yq[100100];
long long x,T;

int main(){
	freopen("subway.in","w",stdin);
	freopen("subway.out ", "r",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		for(int j=1;j<=2*b[i];j++){
			cin>>e[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>xq[i]>>yq[i];
	}
	while(true){
		for(int i=1;i<=q;i++){
			if(e[b[i]][1]==xq[i]){
				for(int j=1;j<=b[i];j++){
					if(yq[i]==e[i][j]){
						for(int k=1;k<=j;k++){
							T+=t[i][k];
						}
						cout<<T<<endl;
						T=0;
						break;
					}
				}
				for(int j=1;j<=b[i];j++){
					for(int k=1;k<=b[i];k++){
						for(int l=1;l<=b[i+k];l++){
							if(e[i][j]==e[k][l]){
								for(int o=1;o<=b[i];o++){
									T+=t[b[i]][o];
								}
						cout<<T<<endl;
						T=0;
						break;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
