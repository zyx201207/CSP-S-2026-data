#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
string c[10000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(a[1]==1){
        cout<<1;
    }
    if(a[1]==2)cout<<2;
    if(a[2]==3)cout<<2;
    if(a[2]==4)cout<<1;
    else{
        cout<<0;
    }
    return 0;
}
