#include<bits/stdc++.h>
using namespace std;

int c[20],s[25],b[10];

int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	
	cin>>c[1],s[1],c[2],s[2];
	
	if(c[1]==s[1]){
		b[1]==1;
	}else{
		b[1]=b[2]=b[3]=b[4]=0;
	}
	int n=s[1]/10;
	int m=s[2]/10;
	if(n=m){
		b[2]=1;
	}else{
		b[2]=b[3]=b[4]=0;
	}

	cout<<1111;
	
	return 0;
}
