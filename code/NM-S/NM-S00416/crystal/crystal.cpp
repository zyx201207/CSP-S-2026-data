#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a1=0,ax;
    cin>>n;
    cin>>m;
    int k[n];
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    sort(k,k+n);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            a1+=(k[i]-k[j]);
            
            
        }
        if(a1>m){
               
            ax=a1;
            cout<<i;
            
            break;
        }
        a1=0;
    }
    return 0;
}
