#include<bits/stdc++.h>
using namespace std;
int M=21e8;
int main(){
	freopen("subway1.in","r",stdin);
    //freopen("subway.out","w",stdout);
    int n,m,d,q,i,j;
    cin>>n>>n>>m>>d>>q;
    int w[m],a[m][n],x,y,z;
    for(i=0;i<m;i++)for(j=0;j<n;j++)a[i][j]=M;
    for(i=0;i<m;i++)cin>>w[i];
	for(i=0;i<n;i++)for(cin>>z;z>0;z--){
		cin>>x>>y;
		a[x][i]=y;
	}
	//for(i=0;i<m;i++){
	//	for(j=0;j<n;j++)cout<<a[i][j]<<',';
	//	cout<<endl;
	//}
	for(;q>0;q--){
		int b[2][m+n+1],k;
		for(i=0;i<m+n+1;i++){
			b[0][i]=M;
			b[1][i]=0;
	    }
		cin>>x>>y;
		x--;
		y--;
		
		b[0][x]=0;
		b[1][x]=1;
		for(i=0;i<m+n;i++){
			k=m+n;
			
			for(j=0;j<m;j++){
				int k1=b[1][j],k2=b[0][j],k3=b[0][k];
				k=(k1?(k2<k3?j:k):k);
				cout<<k1<<' '<<k2<<' '<<k3<<' '<<k<<endl;
			}
			
			b[k][1]=0;
			if(k<m)for(j=0;j<n;j++)if((a[k][j]<M)||(b[0][k]+a[k][j]<b[0][j])){
				b[0][j]=b[0][k]+a[k][j];
				b[1][j]=1;
			}
			else for(j=0;j<m;j++)if((a[j][k-m]<M)||(b[0][k]+a[j][k-m]<b[0][j])){
				b[0][j]=b[0][k]+a[j][k-m];
				b[1][j]=1;
			}
		} 
		cout<<b[0][y]<<endl;
	}
}

