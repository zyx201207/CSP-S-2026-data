#include<bits/stdc++.h>
using namespace std;
char h1,h2;
int c1,c2;
int s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>h1>>c2>>s2>>h2;
    if(c1==c2){
        cout<<'1';
    }else{
        cout<<'0';
    }
    if(s1==s2){
        cout<<'1';
    }else{
        cout<<'0';
    }
    if(h1=='A'&&h2=='B'||h1=='B'&&h2=='A'||h1=='A'&&h2=='C'||h1=='C'&&h2=='A'||h1=='C'&&h2=='B'||h1=='B'&&h2=='C'||h1=='D'&&h2=='F'||h1=='F'&&h2=='D'){
        cout<<'1';
    }else{
        cout<<'0';
    }
    if(h1=='A'&&h2=='B'||h1=='B'&&h2=='A'||h1=='C'&&h2=='B'||h1=='B'&&h2=='C'||h1=='D'&&h2=='F'||h1=='F'&&h2=='D'){
        cout<<'1';
    }else{
        cout<<'0';
    }
    return 0;
}
