#include<bits/stdc++.h>
using namespace std;
int main(){
        freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,d=0;
    cin>>n;
    int a,c;
    char h[50], x[50];
    for(int i=0;i<n;i++){
        cin>>a>>c;
        d+=a;
        for(int j=0;j<a;j++){
            h[j]=c;
        }j=a;
    }for(int i=d;i>=0;i++){
        x[i]=h[i];
    }for(int i=0;i<d;i++){
        if(x[i]==h[i])
            cout<<0;
    }
}
