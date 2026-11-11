#include<bits/stdc++.h>
using namespace std;
int c,t,xx[100005],n,d,f[5005][5005],s[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int da=0;
		cin>>n>>d;
		for(int z=1; z<=n; z++){
			cin>>xx[z];
		}
		for(int z=1; z<=n; z++){
			for(int x=1; x<=n; x++){
				f[z][x]=5005;
				if(abs(z-x)==1){
					f[z][x]=1;
				}
				if(z==x){
					f[z][x]=0;
				}
				if(abs(xx[z]-xx[x])<=d){
					f[z][x]=1;
				}
			}
		}
		for(int x=1; x<=n; x++){
			for(int z=1; z<=n; z++){
				for(int c=z+1; c<=n; c++){
					if(f[z][x]+f[x][c]<f[z][c]){
						s[z][c]=1;
						f[z][c]=f[z][x]+f[x][c];
					}
					else if(f[z][x]+f[x][c]==f[z][c]){
						s[z][c]++;
					}
				}
			}
		}
		for(int z=1; z<=n; z++){
			for(int x=1; x<=n; x++){
				if(f[z][x]==2){
					da++;
				}
			}
		}
		cout<<da<<"\n";
	}
	return 0;
}
