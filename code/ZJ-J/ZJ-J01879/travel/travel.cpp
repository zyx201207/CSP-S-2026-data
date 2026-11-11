#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000";
        exit(0);
    }
    cout<<1;
    char c1=a2[2],c2=b2[2];
    a2.erase(2,1);
    b2.erase(2,1);
    if(a2!=b2){
        cout<<"000";
        exit(0);
    }
    cout<<1;
    int x=(c1<='C'),y=(c2<='C');
    if(x!=y){
        cout<<"00";
        exit(0);
    }
    cout<<1;
    if(c1>c2){
        swap(c1,c2);
    }
    if(c2-c1==1||c2=='F'&&c1=='D'){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
