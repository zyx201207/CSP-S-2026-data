#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    string s1,s2;
    int c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1/10==0){
        c1=c1%10;
    }
    else if(c2/10==0){
        c2=c2%10;
    }
    if(c1==c2){
        cout<<1;
    }
    else{
    	cout<<0;
	}
	cout<<111;
    return 0;
}
