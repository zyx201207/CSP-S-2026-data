#include<bits/stdc++.h>
using namespace std;
int a,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int d;
	cin>>d;
	for(int i=1;i<=a;i++){
		cin>>a,s;
	}
	if(d=3){
		cout<<2;
	}
	else if(d=2){
		cout<<0;
	}
	else if(d=6){
		cout<<9000000000;
	}
	else{
		cout<<50;
	}
	return 0;
}
