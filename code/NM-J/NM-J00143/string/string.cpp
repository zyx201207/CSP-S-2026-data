#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,o=0,p=1,q=0,w=0;
    cin>>n;
    int k[n+5];
    char a[n+5];
    for(int m=1;m<=n;m++){
        cin>>k[m]>>a[m];
        o+=k[m];}
    char l[o+5];
    for(int i=1;i<=n;i++){
        for(;p<=k[i]+q;p++)
            l[p]=a[i];
        q+=k[i];}
    for(int i=1;i<=o/2;i++)
        if(l[i]!=l[o-i])
            w++;
    cout<<w;
    return 0;
}
