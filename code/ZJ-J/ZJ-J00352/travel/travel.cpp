#include<bits/stdc++.h>
using namespace std;
int a1,b1,a2,b2;
char c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>c1;
	cin>>a2>>b2>>c2;
	cout<<a1;
	if(c1>c2){
		swap(c1,c2);
	}
	if(a1!=a2){
		cout<<"0000";
	}else if(b1!=b2){
		cout<<"1000";
	}else if('A'<=c1 and c1<='C' and 'D'<=c2 and c2<='F'){
		cout<<"1100";
	}else if(c1<='C' and c1!='B' and c2!='B'){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}