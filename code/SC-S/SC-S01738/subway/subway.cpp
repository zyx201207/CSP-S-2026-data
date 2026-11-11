#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010][500010],e[2][2];
int main(){
	freopen(subway.in;"r";stdin);
	freopen(subway.out;"m";stdout);
	int c,n,m,d,q,x=0,v,f;
	int i,j,y;
	cin>>c>>n>>m>>d>>q;
	for(i=0;i<m;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		cin>>b[i][0];
		for(j=1;j<=b[i][0]*2;j++){
			cin>>b[i][j];
		}
	}
	for(i=0;i<q;i++)
	{
		for(j=0;j<2;j++){
			cin>>e[i][j];
		}
	}
		
	for(i=0;i<q;i++){
		x=x+a[e[i][0]-1];
		for(j=0;j<n;j++){
			for(y=1;y<b[j][0]*2;y++){
				if(b[j][y]==e[i][0]){
					x=x+b[j][y+1];
					
				}
				if(b[j][y]==e[i][1]){
					x=x+b[j][y+1];
					cout<<x;
				}
			}
		}
		
	} 
	
	return 0;
}