#include<bits/stdc++.h>
using namespace std;
string as,bs;
int a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>as>>b>>bs;
	d=1;
	if(a==b){
		c=1;
	}
	for(int i=0;i<=1;i++){
		if(as[i]!=bs[i]){
			d=0;
		}
	}
	if((as[2]>='D'&&bs[2]>='D')||(as[2]<'D'&&bs[2]<'D')){
		e=1;
	}
    int sc=as[2]-bs[2];
	if(((sc==1&&as[2]!='D')||(sc==-1&&bs[2]!='D'))&&e==1){
		f=1;
	}
	if(c==0){
		d=0;e=0;f=0;
    }
    if(d==0){
    	e=0;f=0;
	}
	cout<<c<<d<<e<<f;
	return 0;
}
