#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	int n,m,x,a,d[5];
cin>>d[5];
	
	for(int i=0;i<2;i++){
			cin>>a>>n;
		if(	d[2]-d[1]==1){
		a==a+1;
		x==d[2]+d[1];
		}
		if(d[3]-x==1){
			a==a+1;
			x==x+d[3];
		}
			if(d[4]-x==1){
			a==a+1;
			x==x+d[4];
		}
			if(d[5]-x==1){
			a==a+1;
			x==x+d[5];
		}
		
	}
		cout<<a+1;

	
	return 0;
} 
