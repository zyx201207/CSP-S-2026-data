#include<bits/stdc++.h>
using namespace std;
string a;
string b;
int c=0,d,z=0;
int s,x;
char e;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>s;
    for(int j=1;j<=s;j++){
        cin>>x>>e;
        for(int i=0;i<x;i++){
            a[j-1+c+i]=e;
            c+=x;
            d=c;
        }
    }

    c/=2;
    for(int i=0;i<=c;i++){
        b[i]=a[c-1-i];
    }
    for(int i=0;i<=d-1;i++){
        if(a[i]!=b[i]) z++;
    }
    cout<<z;
    return 0;
}

