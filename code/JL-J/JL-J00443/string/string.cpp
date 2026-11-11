#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s=0,t=0,a,k=0;
    char f[n],g;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>g;
        for(int i=0;i<a;i++){
            f[k]=g;
            k+=1;
        }
    }
    for(int i=0;i<k;i++){
        if(f[i]!=f[k-i]){
            t+=1;
            f[k-i]=f[i];
        }
    }
    cout<<t;
}
