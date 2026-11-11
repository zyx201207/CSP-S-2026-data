#include<bits/stdc++.h>
using namespace std;
int n,y;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	double x,z;
	cin>>n>>x>>y>>z;
	if(n==y){
		cout<<"1 1 1 1";
	}else{
		cout<<"0 0 0 0";
	}else if(n==y&&x==z){
		cout<<"1 1 0 0";
	}
	return 0;
} 
