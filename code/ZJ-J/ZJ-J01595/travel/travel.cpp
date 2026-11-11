#include<iostream>
using namespace std;
char a[8],b[8],c[8],d[8];
int x,y,z,n,i;
int main(){
	freopen("travel.in","r",std.in);
	freopen("travel.out","w",std.out);
	cin>>a>>b>>c>>d;
	if(a[0]=b[0] ){
		if(a[1]=b[1]){
			x=1;	
		}
	}
	if(b[0]=d[0]){
		if(b[1]=d[1]){
			y=1;
		}
	}
	if('A'<=b[2]<'D'){
		if('A'<=d[2]<'D'){
			i=1;
			z=1;		
		}
	}
	else{
		if('D'<=d[2]<='F'){
			z=1;
			n=1;		
		}
	}
	if(i=1){
		if('A'<b[2]<'C' || 'A'<d[2]<'C'){
			n=1;
		}
	}
	cout<<x<<y<<z<<n;
	return 0;
}
