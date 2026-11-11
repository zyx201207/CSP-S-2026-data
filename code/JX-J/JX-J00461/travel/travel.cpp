#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c=0,v=0,h=0;
	char e,f;
	cin>>a>>e>>b>>f;
	if(a==b){
		c=1;
	}else if(e>b){
		if(e==b+6&&(e-b<=18||e-b<=12)){
			v=1;
	}
	if(b>e){
		if(b==e+6&&(e-b<=18||e-b<=12)){
			v=1;
		}
	}else if(b==e+6||e==b+6){
		h=0;
	}
	cout<<c<<v<<c<<h;
	return 0;
}
}
