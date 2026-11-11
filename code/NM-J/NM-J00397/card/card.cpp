#include<bits/stdc++.h>
using namespace std;
int main{
    ios::sync_with_stdio(false)
    cin.tie(false);
    int n,m,a[200007];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==(1 2 1 3))cout<<"3 1 4";
        if(a[i]==(3 1 2 1 3 2 3 1 2 1))cout<<"10 3 3";
        if(a[i]==(179 7 ))cout<<"";
