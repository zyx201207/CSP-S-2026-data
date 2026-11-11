#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a[1005];
    string b[1005],c,d;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
    }
    for(int i=n+1;i>=0;i--){
       for(int j=a[i];j>=1;j--){
            c+=b[i];
    }
    }
    for(int i=0;i<n+1;i++){
       for(int j=1;j<=a[i];j++){
            d+=b[i];
    }
    }
    if(c==d){
        cout<<0;
    }

     if(c>d){
        cout<<2;
    }
    if(c<d){
        cout<<1;
    }
    return 0;
}
