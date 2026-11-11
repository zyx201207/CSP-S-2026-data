//#include<bits/c++.h>
#include<iostream>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,k=0,b;
    char l[100005];
    cin>>n;
    long long a1[n];
    char c1[n];
    for(int i=0;i<=n;i++){
        cin>>a1[i]>>c1[i];
    }
    for(int j=0;j<n;j++){
        for(int i=0;i<a1[j];i++){
            l[k]=c1[j];
            k+=1;
        }
    }
    for(int i=0;i<k;i++){
        if(l[i]!=l[k-i]){
            b+=1;
        }

    }
    cout<<b-1;
    return 0;
}
