#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,num,a[100]={};
    string b[100]={};
    string c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        c+=b[i];
    }
    int d=2;
    for(int i=1;i<=d;i++){
        if(d%2==0){
           c[d]=c[1];
           num++;
        }
    }
    cout<<num;
    return 0;
}
