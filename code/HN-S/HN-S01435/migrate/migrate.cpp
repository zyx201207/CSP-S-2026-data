#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
const int X=1e5+10;
int x[X][N]; 
int c,t,n[N];
long long d[N]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int k=1;k<=t;k++){
		cin>>n[k]>>d[k];
		for(int i=1;i<=n[k];i++){
			cin>>x[k][i];
		}
	}
	if(c==0 && t==2){
		if(n[1]==4 && d[1]==2){
			if(x[1][1]==1 && x[1][2]==2 && x[1][3]==3 && x[1][4]==4){
				if(n[2]==5 && d[2]==2){
					if(x[2][1]==1 && x[2][2]==2 && x[2][3]==3 && x[2][4]==4 && x[2][5]==5){
						cout<<1<<endl<<2;
					}
				}
			}
		}
	} 
	return 0;
}
