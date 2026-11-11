#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string a,b;
    cin>>n>>a>>m>>b;
    char c=a[2],d=b[2];
    if(n!=m){
        cout<<"0000";
        return 0;
    }
    else{
        for(int i=0;i<2;i++){
        if(a[i]!=b[i]){
            cout<<"1000";
            return 0;
        }
    }
}
    int k=0,j=0;
    if(c>='A' and c<='C'){
        k=1;
    }
    if(d>='A' and d<='C'){
        j=1;
    }
    if(k!=j){
        cout<<"1100";
    }
    else{
        if(abs(c-d)<=1){
            cout<<"1111";
            return 0;
        }
        else{
            cout<<"1110";
            return 0;
        }
    }
}

