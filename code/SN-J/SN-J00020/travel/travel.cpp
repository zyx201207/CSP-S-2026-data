#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c,i,n,e=1,f=1,g=1,h=1;
	int s,u;
	int b[4];
	int d[4];
	cin>>a>>s>>c>>u;
	if(a=c){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((b[i]=d[i+n])||(b[i]=d[i-1]&&(a=c))&&(s=u)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((b[i]=d[i+n])||(b[i]=d[i-n]&&(a=c))&&(s=u)&&(i<2)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if((b[i]=d[i+n])||(b[i]=d[i-n]&&(a=c))&&(s=u)&&(i-1==0)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	

	return 0;
} 
