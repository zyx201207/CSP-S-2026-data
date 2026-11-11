#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("trevel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	int m,n;
	char x,y;
	cin>>a>>m>>x;
	cin>>b>>n>>y;
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(m==n){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((x<='C'&&y<='C')||(x>'C'&&y>'C')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(x==y+1||y==x+1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
