#include<bits/stdc++.h>
using namespace std;
int n,a1,b1,c1,d1;
char a[2],b[3],c[2],d[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[1]==c[1]&&a[0]==c[0]) a1=1; 
	if(a1==1){
		if(b[1]==d[1]&&b[0]==d[0]){
			b1=1;
			if(b[2]>'C'&&d[2]>'C'){
				c1=1;
			}else if(b[2]<='C'&&d[2]<='C'){
				c1=1;
			}
			if(c1==1&&(b[2]+1==d[2]||b[2]-1==d[2])){
				d1=1;
			}
		}
	}	
	cout<<a1<<b1<<c1<<d1;
} 
