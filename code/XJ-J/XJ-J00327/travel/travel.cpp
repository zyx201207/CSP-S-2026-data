#include<bits/stdc++.h>
using namespace std;
int main(){
 	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char q,w,e,r,t,y;
	cin>>a>>q>>w>>e>>b>>r>>t>>y;
	if(a==b&&q==r&&w==t&&((e>='D'&&y>='D')||(e<='C'&&y<='C'))&&(e+1==y||e-1==y)){
		cout<<"1111";
	}else if(a==b&&q==r&&w==t&&((e>='D'&&y>='D')||(e<='C'&&y<='C'))){
		cout<<"1110";
	}else if(a==b&&q==r&&w==t){
		cout<<"1100";
	}else if (a==b){
		cout<<"1000";
	}else{
		cout<<"0000";
	}
	return 0;
}