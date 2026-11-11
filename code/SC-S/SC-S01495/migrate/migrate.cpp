#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],sr[10000][10000],ssr[10000][10000],sssr[10000][10000],ss=0;
void abc(int xx,int y,int z){
	if(z<2){
		for(int i=y+1;i<=n;i++){
			if(i!=xx&&i!=y){
			  	if(max(x[i],x[y])-min(x[i],x[y])<=d){
			  		if(ssr[xx][i]==2){
			  			sssr[xx][i]=min(sssr[xx][i],z+1);
					  }
			  		if(sr[xx][i]==2){
			  			ssr[xx][i]=min(ssr[xx][i],z+1);
					  }
		        	sr[xx][i]=min(sr[xx][i],z+1);
		            abc(xx,i,z+1);
	            }
			}
    	}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ss=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int j=1;j<=n;j++){
			for(int y=1;y<=n;y++){
				sr[j][y]=100000000;
				ssr[j][y]=100000000;
				sssr[j][y]=100000000;
			}
			sr[j][j]=0;
			ssr[j][j]=0;
			sssr[j][j]=0;
			abc(j,j,0);
		}
		for(int j=1;j<=n;j++){
			for(int y=1;y<=n;y++){
				if(sr[j][y]==2&&ssr[j][y]==2){
					if(sssr[j][y]!=2){
						ss=ss+1;
					}
				}
			}
		}
		cout<<ss<<endl;
	}
	return 0;
}