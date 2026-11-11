#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[505],a,t[505][505],b,xx[505],yy[505],aa[505],tt[505][505],f[100005],zz;
void fs(int i){
	for(int j=1;j<=n;j++){
		if(t[j][i]>0){
			aa[j]=yy[i];
			for(int z=1;z<=m;z++){
				if(t[j][z]>0 && yy[z]==0){
					yy[z]=yy[i];
					fs(z);
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
		cin>>a;
		for(int j=1;j<=a;j++){
			cin>>b;
			cin>>t[i][b];
		}
	}
	zz=1;
	xx[1]=zz;
	yy[1]=1;
	fs(1);
	for(int aa=2;aa<=m;aa++){
		if(yy[aa]==0){
			zz++;
			yy[aa]=zz;
			fs(aa);
		}
	}
	for(int i=1;i<=zz;i++){
		for(int j=1;j<=zz;j++){
			if(yy[i]==yy[j]){
				tt[i][j]=0;
			}
			tt[i][j]=INT_MAX;
			for(int z=1;z<=m;z++){
				if(yy[z]==yy[i]){
					for(int s=1;s<=a;s++){
						if(t[s][z]!=0){
							tt[i][j]=min(tt[i][j],tt[i][j]+t[s][z]);
						}
					}
				}
			}
			b=INT_MAX;
			for(int z=1;z<=m;z++){
				if(yy[z]==yy[j]){
					for(int s=1;s<=a;s++){
						if(t[s][z]!=0){
							b=min(b,t[s][z]);
						}
					}
				}
			}
			tt[i][j]+=b;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>a;
		cin>>b;
		f[i]=tt[a][b]+w[a]+w[b];
	}
	for(int i=1;i<=q;i++){
		cout<<f[i]<<endl;
	}
}
