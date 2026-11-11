#include <bits/stdc++.h>
using namespace std;
char a[100],b[100],c[100],d[100];
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	//for(int i=1;i<=4;i++){
	cin>>a[0]>>b[0]>>c[0]>>d[0];
	
	//}
	if(a[0]=c[0]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(b[0]=d[0]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(b[1]=d[1]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(b[2]=d[2]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
