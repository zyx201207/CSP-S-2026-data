#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c[100086],d=0;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    for(int i=1;i<=b;i++){
        if(a[i]!=a[i-1]){
            a[i]++;
        }
        else{
            a[i]+=a[i+1];
            d++;
        }
    }
    cout<<d;
    return 0;
}
