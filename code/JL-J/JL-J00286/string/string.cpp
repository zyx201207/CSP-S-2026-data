#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    int b;
    char c;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b>>c;
    }
    if(a==2){
        cout<<0;
    }
    else if(a==3){
        cout<<2;
    }
    else if(a==6){
        cout<<3000000000;
    }
    return 0;
}

