#include<bits/stdc++.h>
using namespace std;
int main(){
string a,b,c,d;
int e=0,f=0,g=0,h=0;
freeopen("travel.in","r",stdin);
freeopen("travel.out","w",stdout);
cin>>a>>b>>c>>d;
if(a==c){
	e=1;
	if(b[0]==d[0] and b[1]==d[1]){
		f=1;
		if(b[2]>'C' and d[2]>'C'){
			g=1;
			if(b[2]==d[2]+1 or b[2]==d[2]-1){
				h=1;
				}
		}else if(b[2]<='C' and d[2]<='C'){
			g=1;
			if(b[2]==d[2]+1 or b[2]==d[2]-1){
				h=1;
				}
			}
	}


}
cout<<e<<f<<g<<h;
	return 0;
}
