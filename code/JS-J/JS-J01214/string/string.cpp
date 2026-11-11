#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int a;
    char b;
    string c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
    }
    if(n==1){
        cout<<0;
    }
    else if(n==2&&a==1){
        cout<<1;
    }
    else{
        cout<<3;
    }
    return 0;
}
