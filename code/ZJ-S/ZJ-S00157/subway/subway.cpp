#include<bits/stdc++.h>
using namespace std;
long long w[5000005],k[5000005];
long long z[11451][11451];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q,a,b;
	cin>>c>>n>>m>>d>>q;
	for(long long i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i = 1;i<=n;i++){
		cin>>k[i];
		for(long long j = 1;j<=k[i];j++){
			cin>>a>>b;
			z[a][i] = b;
		}
	}
	while(q--){
		int x,y,t=0;
		int f1=0,f2=0;
		cin>>x>>y;
		t += w[x];
		for(int i = 1;i<=n;i++){
			if(z[x][i] != 0 && z[y][i] != 0){
				t += z[x][i] + z[y][i] + w[y];
				f1 = 1;
				break;
			}
		}
		if(f1 == 0){	
			for(int i = 1;i<=m;i++){
				if(z[i][1] != 0 && z[i][2] != 0){
					if(z[x][1] != 0){
						t+=z[x][1] + z[i][1] + z[i][2] + z[y][2] + w[y];
					} 
					else{
						t+=z[x][2] + z[i][2] + z[i][1] + z[y][1] + w[y];
					}
					break;
				}
			}
		}
		cout<<t<<endl;
	}
	return 0;
}