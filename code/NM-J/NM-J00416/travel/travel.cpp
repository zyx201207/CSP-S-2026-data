#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1;
    int c2;
    int p1;
    int p2;
    char z1,z2;
    cin>>c1>>p1>>z1>>c2>>p2>>z2;
    if(c1!=c2){
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(c1==c2){
    	cout<<1;
	}else{
		cout<<0;
	}
	if(p1==p2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(z1=='D'&&z2=='F'||z2=='D'&&z1=='F'){
		cout<<1;
		cout<<1;
	}else{
		cout<<1;
		if(z1=='A'&&z2=='B'||z2=='A'&&z1=='B'||z1=='B'&&z2=='C'||z2=='B'&&z1=='C'){
			cout<<1;
		}else{
			cout<<0;
		}
	}
    return 0;
}
