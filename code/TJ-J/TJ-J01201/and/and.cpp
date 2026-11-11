#include <bits/stdc++.h>
using namespace std;

int TENn,m,malong=0,TWOn[200010];
string TWOc[200010];

long long TTTo(int Ten){
	long long Two=0;
	while(Ten/2||Ten%2){
		if(Ten%2)Two=Two*10+1;
		else Two=Two*10;
		Ten/=2;
	}
	return Two;
}

long long AND(int a,int b){
	long long c=0;
	for(int i=0;i<min(a,b);i++)
	c=(a%10&&b%10)+c*10;
	return c;
}


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    
    cin>>TENn>>m;
    for(int i=1;i<=TENn;i++){
    	cin>>TENn;
    	TWOn[i]=TTTo(TENn);
	}
	
	cout<<AND(TWOn[1],TWOn[2]);
	
	
    
    return 0;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
