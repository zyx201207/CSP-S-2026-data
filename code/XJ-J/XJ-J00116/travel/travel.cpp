#include<bits/stdc++.h>
using namespace std;
string a,b,aa,bb;
bool x,y,z,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a==b){
		cout<<1;
		x=1;
	}
	else{
		cout<<0;
	}
	if(x&&aa[0]==bb[0]&&aa[1]==bb[1]){
		cout<<1;
		n=1;
	}
	else{
		cout<<0;
	}
	if(n&&aa[2]<='C'&&bb[2]<='C'){
		y=1;
		if(abs(aa[2]-bb[2])==1){
			z=1;
		}
	}
	if(n&&aa[2]>='D'&&bb[2]>='D'){
		y=1;
		z=1;
	}
	if(y){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(x&&y&&z&&n){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
