#include<bits/stdc++.h>
using namespace std;
int a[500067];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cout<<a[i]/2+a[i]%5<<' ';
    }
}
