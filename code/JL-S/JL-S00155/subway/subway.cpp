#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m];
    for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k[n];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<2*k[i];j++){
			cin>>a[i][j];
		}
	}
	int x[q],y[q];
	for(int i=0;i<q;i++){
		int u=1000;
		cin>>x[i]>>y[i];
		int b=w[x[i]-1]+w[y[i]-1];
		int e1=100,f1=0,e2=100,f2=0,g=100;
		for(int j=0;j<n;j++){
			for(int z=0;z<2*k[j]-1;z+=2){
				if(a[j][z]==x[i]&&a[j][z+1]<e1){
					e1=a[j][z+1];
					f1=j;
				}
				if(a[j][z]==y[i]&&a[j][z+1]<e2){
					e2=a[j][z+1];
					f2=j;
				}
				if(f1==f2&&e1+e2<u){
					u=e1+e2;
				}
			}
		}
		int h=b;
		    b+=e1;
		    b+=e2;
		if(f1==f2) cout<<b;
		else{
			for(int j=0;j<2*k[f1];j+=2){
				for(int z=0;z<2*k[f2];z+=2){
					if(a[f1][j]==a[f2][z]&&a[f1][j+1]+a[f2][z+1]<g){
						g=a[f1][j+1];
						g+=a[f2][z+1];
					}
				}
			}
	    b+=g;
	    h+=u;
	    if(b<h) cout<<b;
	    else cout<<h;
		}
		
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
