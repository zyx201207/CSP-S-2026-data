#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool flag=true;
    for(int i=0;i<m-1;i++){
        if(a[i]<a[i-1]){
            flag=false;
        }
    }
    if(flag){
        for(int i=0;i<n+1;i++){
            if(a[i+1]!=a[i]){
                cout<<i+1<<" ";
            }
        }
    }
    return 0;
}