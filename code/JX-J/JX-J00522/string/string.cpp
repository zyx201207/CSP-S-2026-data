#include <bits/stdc++.h>
using namespace std;
long long n,a[15],x;
string c,S,S1;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<a[i];i++){
            S+=c[i];
        }
    }
    for(int i=0;i<=n;i++){
        x+=a[i];
    }
    for(int i=0;i<=x;i++){
        S1[x-i]=S[i];
    }
    if(S==S1){
        cout<<0;
    }else{cout<<2;
    }
}
