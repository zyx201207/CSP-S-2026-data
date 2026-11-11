#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int c1,c2;
	char w1[4],w2[4];
	
	cin>>c1>>w1;
	cin>>c2>>w2;
	int h1=w1[0]*10+w1[1];
	int h2=w2[0]*10+w2[1];
	char v1=w1[2];
	char v2=w2[2];
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(h1==h2){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(v1>='A'&&v1<='C' &&v2>='A'&&v2<='C' || v1>='D'&&v1<='F' &&v2>='D'&&v2<='F' ){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(v1==v2+1 || v1==v2-1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
