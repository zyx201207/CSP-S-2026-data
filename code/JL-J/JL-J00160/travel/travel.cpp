#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    string x,y;

    cin>>a>>b>>x>>c>>d>>y;
    int j=x;
    char i=y;
    if(a==c){
        cout<<1;
    }
    if(a==c&&b==d){
        cout<<1;
    }
    if(a==c&&b==d&&(j-i==-1||j-i==1)){
        cout<<1;
    }
    if(a==c&&b==d&&x!="C"&&y!="D"){
        cout<<1;
    }
    if(a==c&&b==d&&x!="D"&&y!="C"){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
