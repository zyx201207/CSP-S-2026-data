#include <bits/stdc++.h>
using namespace std;
int f[100000005],p[100000005],g[100000005],h[100000005];
int main(){
    freopen("treval.in","r",stdin);
    freopen("treval.out","w",stdout);
    string a,b,c,d;
    for (int i=1;i<=2;i++){
        f[i]=a[i];
    }
    for (int i=1;i<=3;i++){
        p[i]=b[i];
    }
    for (int i=1;i<=2;i++){
        g[i]=c[i];
    }
    for (int i=1;i<=3;i++){
        h[i]=d[i];
    }
    if (a==c)
    {
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if (p[0]+p[1]==h[0]+h[1]){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if (p[2]==h[2]){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    if (p[2]+1==h[2]){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
