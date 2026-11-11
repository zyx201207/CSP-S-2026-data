#include<bits/stdc++.h>
using namespace std;
long long q,c,t,n,d,x[10000],e[10000][10000],e2[10000][10000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		q=0;
		for(int j=1;j<=t;j++){
			cin>>x[j];	
		}
		for(int j=1;j<=n;j++){
			for(int z=j;z<=n;z++){
				if(x[z]-x[j]<=d){
					e[z][j]=x[z]-x[j];
				} 
			}
		}
		
		for(int j=1;j<=n;j++)
			for(int z=j;z<=n;z++)
				for(int u=z;u<=n;u++){
					if(e[j][z]+e[z][u]<e[j][u]){
						e[j][u]=e[j][z]+e[z][u];
						if(e2[j][u]==1){
							q--; 
						}
						e2[j][u]=0;
					}else if(e[j][z]+e[z][u]==e[j][u]){
						if(e2[j][u]==0){
							q++; 
							e2[j][u]++;
						}else{
							q--;
							e2[j][u]++;
						}
					}
				}
			
		cout<<q<<endl;
	}
	
	return 0;
} 