#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010][500010],e[2][2];
int main(){
	freopen(migrate.in;"r";stdin);
	freopen(migrate.out;"m";stdout);
	int c,t,n,d,i,j,x=0,y,f=0;
	cin>>c>>t;
	for(i=0;i<t;i++){
		for(j=0;j<2;j++){
			cin>>b[i][j]; 
		}
		for(j=0;j<t;j++)
		{
			cin>>b[i+1][j];
		}
	}
	for(i=0;i<t;i+=2){
		for(j=0;j<b[i][0];j++){
			for(y=1;y<b[i][0];y++){
				if(b[i+1][y]=b[i+1][j]+2*b[i][1]-1) x++;
				if(b[i+1][y]=b[i+1][j]+b[i][1]) x++;
				if(b[i+1][y]=b[i+1][j]+b[i][1]-1) x++;
				if(x==3) f++;
			}
			x=0;
		}
		cout<<f<<' ';
		f=0;
	}
	
	return 0;
}